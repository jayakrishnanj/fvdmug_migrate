<?php

class FvdmugMigrateList extends MigrateList {

    public function __toString() {
        return __CLASS__;
    }

    public function count() {
        return $this->computeCount();
    }
    
    public function computeCount() {
        return count($this->getIdList());
    }

    public function getIdList() {
        $files = array();
        foreach (array_diff(scandir('public://fvdmug_images'), array('.', '..')) as $file) {
            $files[] = str_replace('.jpg', '', $file);
        }
        return $files;
    }

    public function fields() {
        return array(
          'id' => t('ID of the image.'),
          'uri' => t('URI of the image.'),
        );
    }
    
}
