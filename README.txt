FVDMUG Migrate
===============

Examples of using the Drupal Migrate module to migrate various sources of data
into Drupal.

Instructions:
--------------

  1) Place the files for the FVDMUG Migrate module into your site's module 
     directory. Also load in dependencies of the module.

  2) Enable the FVDMUG Migrate module along with the Migrate UI module.

  3) Once everything is enabled, you should have 3 new content types, Color, 
     Image, and Purchase. You will also have 3 new items added to the main menu
     which link to views that list each content type.

  4) To conduct a migration, navigate to admin/content/migrate, select the
     desired migration(s), then execute the import. For more information on how
     to conduct the migrations, please refer to documentation for the Migrate
     module at https://drupal.org/project/migrate.

SQL Migration:
---------------
  The FvdmugSql migration is an example of migrating data from a SQL table into
  nodes. The table is built and populated when this module is enabled as a 
  convenience but is intended to simulate migrating data in from other tables in
  the database or other tables in a different database accessible by the Drupal
  site.

CSV Migration:
---------------
  The FvdmugCsv migration is a example of migrating data from a CSV source into
  nodes. The source file is contained within this module at 
  FvdmugCsvMigration/FvdmugCsvMigration.inc.

File Migration:
----------------
  The FvdmugImg migration is an example of migration data in files into nodes. 
  This example implements a MigrateList class which scans for .jpg files in 
  FvdmugImgMigration/images directory and provides data for each item via a 
  MigrateItem class.

FVDMUG Migrate Feature:
------------------------
  The FVDMUG Migrate Feature module is a dependency which configures 3 content
  types in which the example migrations put content. It also contains a view so
  you can see the content listed after the migration.
