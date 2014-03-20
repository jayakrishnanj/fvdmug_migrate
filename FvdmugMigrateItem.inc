<?php

class FvdmugMigrateItem extends MigrateItem {

    /**
     * Makes a row out of an ID.
     */
    public function getItem($id) {
        $row = new stdClass();
        $row->id = $id;
        $row->uri = "public://fvdmug_images/$id.jpg";
        return $row;
    }

}
