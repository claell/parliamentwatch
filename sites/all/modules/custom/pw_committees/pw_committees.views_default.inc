<?php
/**
 * @file
 * pw_committees.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pw_committees_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'pw_commitee_terms';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'PW Commitee terms';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Committees';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'iarratas a dhéanamh';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '11';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = 'first';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'zurück';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'last';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'pw-list-item clearfix';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Feld: i18title */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'i18title';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['php']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
global $language;
//print_r(i18n_string("taxonomy:term:".$data->_field_data[\'tid\'][\'entity\']->tid.":description",$data->_field_data[\'tid\'][\'entity\']->description,array(\'langcode\' => $language->language)));
print i18n_taxonomy_term_name($data->_field_data[\'tid\'][\'entity\']);


?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_type'] = 'h3';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Feld: Taxonomie-Begriff: Picture */
  $handler->display->display_options['fields']['field_committee_picture']['id'] = 'field_committee_picture';
  $handler->display->display_options['fields']['field_committee_picture']['table'] = 'field_data_field_committee_picture';
  $handler->display->display_options['fields']['field_committee_picture']['field'] = 'field_committee_picture';
  $handler->display->display_options['fields']['field_committee_picture']['label'] = '';
  $handler->display->display_options['fields']['field_committee_picture']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_committee_picture']['element_class'] = 'file-image float-left portrait-l';
  $handler->display->display_options['fields']['field_committee_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_committee_picture']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_committee_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_committee_picture']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_committee_picture']['settings'] = array(
    'file_view_mode' => 'pw_file_portrait_l',
  );
  /* Feld: i18nDescription */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['ui_name'] = 'i18nDescription';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['php_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php 
global $language;
print i18n_string("taxonomy:term:".$data->_field_data[\'tid\'][\'entity\']->tid.":description",$data->_field_data[\'tid\'][\'entity\']->description,array(\'langcode\' => $language->language));
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Feld: Taxonomie-Begriff: Begriffsbeschreibung */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['description']['element_default_classes'] = FALSE;
  /* Feld: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'committee details';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'taxonomy/term/[tid]';
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'float-right link-committees';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Kontextfilter: Feld: Parliament (field_parliament) */
  $handler->display->display_options['arguments']['field_parliament_tid']['id'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['arguments']['field_parliament_tid']['field'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_parliament_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_parliament_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_parliament_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_parliament_tid']['validate_options']['vocabularies'] = array(
    'parliaments' => 'parliaments',
  );
  $handler->display->display_options['arguments']['field_parliament_tid']['validate_options']['type'] = 'convert';
  /* Filterkriterium: Taxonomie-Vokabular: Maschinenlesbarer Name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'committee' => 'committee',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'committees/%';
  $export['pw_commitee_terms'] = $view;

  return $export;
}
