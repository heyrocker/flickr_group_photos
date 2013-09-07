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

  /**
   * Render the field.
   *
   * @param $values
   *   The values retrieved from the database.
   */
  function render($values) {
    $image_info = array(
    	  'path' => $values->{$this->field},
    	  'style_name' => 'thumbnail',
  	);
  	$return = theme('imagecache_external', $image_info);
  }

}
