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
    $photos = $flickr->groups_pools_getPhotos('2221193@N21', NULL, NULL, NULL, NULL, 20);
    foreach ($photos['photos']['photo'] as $photo) {
      $row = new stdClass;
      $photo_id = $photo['id'];
      $info = $flickr->photos_getInfo($photo_id);
      $row->title = $info['photo']['title'];
      $view->result[] = $row;
    }
  }

}
