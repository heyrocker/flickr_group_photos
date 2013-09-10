<?php

/**
 * @file
 *   Views field handler for Flickr group images.
 */

/**
 * Views field handler for Flickr group images.
 */
class flickr_group_photos_field_image extends views_handler_field {

  /**
   * Called to add the field to a query.
   */
  function query() {
    $this->field_alias = $this->real_field;
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['image_style'] = array('' => '-');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    // Offer a list of image styles for the user to choose from.
    parent::options_form($form, $form_state);

    $form['image_style'] = array(
      '#title' => t('Image style'),
      '#type' => 'select',
      '#default_value' => $this->options['image_style'],
      '#options' => image_style_options(FALSE),
    );
  }

  /**
   * Render the field.
   *
   * @param $values
   *   The values retrieved from the database.
   */
  function render($values) {
    $image_info = array(
    	  'path' => $values->{$this->field},
    	  'style_name' => $this->options['image_style'],
  	);
  	return theme('imagecache_external', $image_info);
  }

}
