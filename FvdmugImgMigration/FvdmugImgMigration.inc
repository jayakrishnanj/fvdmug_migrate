<?php

class FvdmugImgMigration extends Migration {

    public function __construct() {
        parent::__construct();

        $this->description = t('Import image files into nodes.');

        // Since our source (MigrateSourceList) can't be aware of the fields 
        // available, we'll set that data here. This is not required, only for
        // reference on the Migration's UI.
        $fields = array(
          'id' => t('ID of the image.'),
          'path' => t('Path to the image.'),
          'size' => t('Size of the image.'),
        );
        $this->source = new MigrateSourceList(new FvdmugMigrateList(), new FvdmugMigrateItem(), $fields);
        $this->destination = new MigrateDestinationNode('fvdmug_image');

        // Set up a Map relating source rows to destination records.
        $source_key = array(
          'img' => array(
            'type' => 'varchar',
            'length' => 255,
            'not null' => TRUE,
          ),
        );
        $this->map = new MigrateSQLMap('fvdmug_image', $source_key, MigrateDestinationNode::getKeySchema());
        
        // Mapped fields.
        $this->addFieldMapping('title', 'id');
        $this->addFieldMapping('promote', 'promote');
        $this->addFieldMapping('field_image', 'path');
        $this->addFieldMapping('field_filesize', 'size');
        $this->addFieldMapping('field_modified', 'modified');
    }

    public function prepareRow($row) {
        // Here's our chance to adjust the source row prior to being mapped onto
        // the destination fields.
        $row->id .= ' ' . date('g:ia', REQUEST_TIME);

        // Hard code these to be promoted.
        $row->promote = TRUE;

        // We can also provide brand new data.
        $row->modified = filemtime($row->path);
    }

}
