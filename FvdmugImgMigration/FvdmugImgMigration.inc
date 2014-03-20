<?php

class FvdmugImgMigration extends DynamicMigration {

    public function __construct() {
        parent::__construct();

        $this->description = t('Import image files into nodes.');

        // Set up the source and destination.
        $this->source = new MigrateSourceList(new FvdmugMigrateList(), new FvdmugMigrateItem());
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
        $this->addFieldMapping('promoted', 'promoted');
        $this->addFieldMapping('field_image', 'path');
        $this->addFieldMapping('field_filesize', 'size');
        $this->addFieldMapping('field_modified', 'modified');
    }

    public function prepareRow($row) {
        // Here's our chance to adjust the source row prior to being mapped onto
        // the destination fields.
        $row->id .= ' ' . date('g:ia', REQUEST_TIME);
        
        // We can also provide brand new data.
        $row->modified = filemtime($row->path);
    }

}
