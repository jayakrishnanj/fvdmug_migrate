<?php

/**
 * @file
 * FVDMUG Migrate migration hook.
 */

/**
 * Implements hook_migrate_api().
 */
function fvdmug_migrate_migrate_api() {
  $api = array(
    'api' => 2,
    'migrations' => array(
      'FvdmugImg' => array('class_name' => 'FvdmugImgMigration'),
    ),
  );
  return $api;    
}
