<?php

class FvdmugCsvMigration extends Migration {

    public function __construct() {
        parent::__construct();
        
        $this->description = t('Import executive orders from a CSV into nodes.');
        
        // Set up the source.
        $path = drupal_get_path('module', 'fvdmug_migrate') . '/FvdmugCsvMigration/orders.csv';
        $columns = array(
          0 => array('order_no', t('Order number.')),
          1 => array('product', t('Product purchased.')),
          2 => array('date', t('Date of the purchase.')),
          3 => array('price', t('Price of the purchase.')),
          4 => array('vendor', t('Vendor purchased through.')),
          5 => array('description', t('Description of the purchase.')),
        );
        $options = array('header_rows' => TRUE);
        $fields = array(
          'order_no' => t('Order number.'),
          'product' => t('Product purchased.'),
          'date' => t('Date of the purchase.'),
          'price' => t('Price of the purchase.'),
          'vendor' => t('Vendor purchased through.'),
          'description' => t('Description of the purchase.'),
        );
        $this->source = new MigrateSourceCSV($path, $columns, $options, $fields);

        // Set up the destination.
        $options = array();
        $this->destination = new MigrateDestinationNode('fvdmug_purchase', $options);
        
        // Set up the map.
        $source_key = array(
          'order_no' => array(
            'type' => 'int',
            'not null' => TRUE,
          ),
        );
        $this->map = new MigrateSQLMap(__CLASS__, $source_key, MigrateDestinationNode::getKeySchema());
        
        // Map the fields.
        $this->addFieldMapping('title', 'product');
        $this->addFieldMapping('body', 'description');
        $this->addFieldMapping('created', 'date');
        $this->addFieldMapping('field_order_no', 'order_no');
        $this->addFieldMapping('field_price', 'price');
        $this->addFieldMapping('field_vendor', 'vendor');
    }

    /**
     * Make changes to the row before it's mapped onto the destination fields.
     */
    public function prepareRow($row) {
        parent::prepareRow($row);
        
        // Convert to Unix timestamp.
        $row->date = strtotime($row->date);
        
        // Kill dollar signs and commas in prices.
        $row->price = strtr($row->price, array('$' => '', ',' => ''));
    }
    
}
