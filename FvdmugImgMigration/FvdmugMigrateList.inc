<?php

/**
 * Example of providing a Migration source using files on the disk.
 */
class FvdmugMigrateList extends MigrateList {

    /**
     * Provides a string reported as the "query" in the Migrate UI.
     */
    public function __toString() {
        return __CLASS__;
    }

    /**
     * Provide a count of items available for the migration.
     * 
     * This functionality is already available via the count() method, so we'll
     * just call it instead of duplicating.
     */
    public function count() {
        return $this->computeCount();
    }
    
    /**
     * Provide a count of items available for the migration.
     */
    public function computeCount() {
        return count($this->getIdList());
    }

    /**
     * Provide a list of item IDs available for migration.
     */
    public function getIdList() {
        $path = drupal_get_path('module', 'fvdmug_migrate') . '/FvdmugImgMigration/images';
        $files = glob($path . '/*.jpg');
        $files = array_map('basename', $files);
        return $files;
    }

    /**
     * 
     */
    public function fields() {
        return array(
          'id' => t('ID of the image.'),
          'path' => t('Path to the image.'),
          'size' => t('Size of the image.'),
        );
    }
    
}
