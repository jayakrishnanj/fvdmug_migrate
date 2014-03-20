<?php
/**
 * @file
 * fvdmug_migrate_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fvdmug_migrate_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function fvdmug_migrate_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function fvdmug_migrate_feature_node_info() {
  $items = array(
    'fvdmug_color' => array(
      'name' => t('Color'),
      'base' => 'node_content',
      'description' => t('Information for HTML colors.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'fvdmug_image' => array(
      'name' => t('Image'),
      'base' => 'node_content',
      'description' => t('Image and related information.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'fvdmug_purchase' => array(
      'name' => t('Purchase'),
      'base' => 'node_content',
      'description' => t('Data describing a purchase.'),
      'has_title' => '1',
      'title_label' => t('Product'),
      'help' => '',
    ),
  );
  return $items;
}
