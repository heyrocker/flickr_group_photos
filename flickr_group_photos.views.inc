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

