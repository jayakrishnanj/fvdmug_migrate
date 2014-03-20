<?php

class FvdmugImgMigration extends DynamicMigration {

    public function __construct() {
        parent::__construct();

        // Set up the source and destination.
        $this->source = new MigrateSourceList(new FvdmugMigrateList(), new FvdmugMigrateItem());
        $this->destination = new MigrateDestinationNode('fvdmug_image');
        
        $source_key = array('img' => array(
            'type' => 'int',
            'not null' => TRUE,
           )
         );
        $this->map = new MigrateSQLMap('fvdmug_image', $source_key, MigrateDestinationNode::getKeySchema());
        
        // Mapped fields.
        $this->addFieldMapping('title', 'id');
        $this->addFieldMapping('field_image', 'uri');
    }

    public function prepareRow($row) {
        // Here's our chance to adjust.
        //$row->id .= ' ' . date('g:ia', REQUEST_TIME);
    }

}
