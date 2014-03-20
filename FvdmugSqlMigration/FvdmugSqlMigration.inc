<?php

class FvdmugSqlMigration extends Migration {
    
    public function __construct() {
        parent::__construct();
        
        $this->description = t('Migrate HTML color codes.');
        
        // Set up the source and destination.
        $query = db_select('fvdmug_migrate_html_colors', 'c')->fields('c');
        $this->source = new MigrateSourceSQL($query);
        $this->destination = new MigrateDestinationNode('fvdmug_color');
        
        // Set up the map.
        $source_key = array(
          'color' => array(
            'type' => 'varchar',
            'length' => 255,
            'not null' => TRUE,
          ),
        );
        $this->map = new MigrateSQLMap(__CLASS__, $source_key, MigrateDestinationNode::getKeySchema());
        
        // Map the fields.
        $this->addFieldMapping('title', 'color');
        $this->addFieldMapping('field_hex', 'hex');
    }
    
}
