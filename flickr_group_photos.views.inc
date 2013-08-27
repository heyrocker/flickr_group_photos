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
    'title' => t('Flickr Groups'),
    'help' => t('Query Flickr groups.'),
    'query class' => 'flickr_group_photos_plugin_query'
  );
  return $data;
}
