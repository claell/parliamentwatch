<?php
/**
 * @file
 * pw_kandidatencheck.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function pw_kandidatencheck_taxonomy_default_vocabularies() {
  return array(
    'pw_kc_votes' => array(
      'name' => 'KC Votes',
      'machine_name' => 'pw_kc_votes',
      'description' => 'Voting behavior in Kandidatencheck',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '1',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
