<?php

/**
 * Implementation of hook_views_plugins().
 */
function flickr_group_photos_views_plugins() {
  $plugin = array();
  $plugin['query']['flickr_group_photos_plugin_query'] = array(
    'title' => t('Flickr Groups Query'),
    'help' => t('Flickr Groups query object.'),
    'handler' => 'flickr_group_photos_plugin_query',
  );
  return $plugin;
}

/**
 * Implementation of hook_views_data().
 */
function flickr_group_photos_views_data() {
  $data = array();

  // Base data
  $data['flickr_group_photos']['table']['group']  = t('Flickr Groups');
  $data['flickr_group_photos']['table']['base'] = array(
    'title' => t('Flickr Group Photos'),
    'help' => t('Query Flickr groups.'),
    'query class' => 'flickr_group_photos_plugin_query'
  );

  // Fields
  $data['flickr_group_photos']['title'] = array(
    'title' => t('Title'),
    'help' => t('The title of this photo.'),
    'field' => array(
      'handler' => 'flickr_group_photos_handler_field',
    ),
  );
  $data['flickr_group_photos']['image'] = array(
    'title' => t('Image'),
    'help' => t('The actual image from Flickr.'),
    'field' => array(
      'handler' => 'flickr_group_photos_field_image',
    ),
  );

  return $data;
}
