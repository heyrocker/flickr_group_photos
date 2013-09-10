<?php

/**
 * @file
 *   Views query plugin for Flickr group photos.
 */

/**
 * Views query plugin for the Flickr group photos.
 */
class flickr_group_photos_plugin_query extends views_plugin_query {

  function query($get_count = FALSE) {  }

  function execute(&$view) {
    $flickr = flickrapi_phpFlickr();
    $photos = $flickr->groups_pools_getPhotos($this->options['group_id'], NULL, NULL, NULL, NULL, $this->options['num_photos']);
    foreach ($photos['photos']['photo'] as $photo) {
      $row = new stdClass;
      $photo_id = $photo['id'];
      $info = $flickr->photos_getInfo($photo_id);
      $row->title = $info['photo']['title'];
      $sizes = $flickr->photos_getSizes($photo_id);
      foreach ($sizes as $size) {
        if ($size['label'] == 'Original') {
          $row->image = $size['source'];
        }
      }
      $view->result[] = $row;
    }
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['num_photos'] = array(
      'default' => '20',
    );
    $options['group_id'] = array(
      'default' => '',
    );

    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form = parent:: options_form($form, $form_state);

    $form['num_photos'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of photos'),
      '#description' => t('The number of photos that should be returned from the specified group.'),
      '#default_value' => $this->options['num_photos'],
    );
    $form['group_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Flickr group ID'),
      '#description' => t('The ID of the Flickr group you want to pull photos from. This is a string of the format ######@N00, and it can be found in the URL of your group\'s "Invite Friends" page.'),
      '#default_value' => $this->options['group_id'],
    );
  }

}
