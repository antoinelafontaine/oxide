<?php

/**
 * @file
 * Drush commands for Oxide template engine.
 */

/**
 * Implementation of hook_drush_command().
 */
function oxide_drush_command() {
  $items['oxide-cache-clear'] = array(
    'callback' => 'oxide_template_cache_clear',
    'description' => dt('Oxide Theme Engine - Remove all rendered templates from the Oxide cache folder. (occ)'),
    'aliases' => array('occ'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );
  return $items;
}

/**
 * Implementation of hook_drush_help().
 */
function oxide_drush_help($section) {
  switch ($section) {
    case 'drush:oxide-cache-clear':
      return dt("Oxide Theme Engine - Remove all rendered templates from the Oxide cache folder. (occ)");
  }
}

function oxide_template_cache_clear() {
  # Needs sudo to work for now...
  # Can't figure out why I can't get it to use boostraped Drupal to avoid permissions problems
  $template_cache_path_base = file_default_scheme() . '://oxide/';

  drush_print( dt('Oxide Theme Engine - Cache path: ') . drupal_realpath($template_cache_path_base) );

  if( drush_delete_dir( drupal_realpath($template_cache_path_base), true ) ){
    drush_print( dt('Oxide Theme Engine - Rendered template cache emptied!') );
  } else {
    drush_print( dt('Oxide Theme Engine - You should probably run this as a super user (sudo) or change the file permission on the cache folder.') );
  }
}