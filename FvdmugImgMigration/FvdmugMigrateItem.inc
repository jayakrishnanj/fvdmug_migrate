<?php

/**
 * Example of a MigrateItem utilized by a MigrateList.
 * 
 * This class is responsible for creating a row of source data to be processed
 * by a Migration.
 */
class FvdmugMigrateItem extends MigrateItem {

    /**
     * Instantiate a row from an ID.
     */
    public function getItem($id) {
        $row = new stdClass();
        $row->id = $id;
        $path = drupal_get_path('module', 'fvdmug_migrate') . '/FvdmugImgMigration/images';
        $row->path = "$path/$id";
        $row->size = filesize($row->path);
        return $row;
    }

}
