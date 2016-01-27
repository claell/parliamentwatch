<?php

Function pw_search_api_facetapi_filters()
{
    return array(
        'rewrite_items' => array(
            'handler' => array(
                'label' => t('Wahlkreise zu Ortsnamen auflösen'),
                'class' => 'FacetapiFilterRewriteItems1',
            ),
        ),
      'rewrite_items2' => array(
        'handler' => array(
          'label' => t('Inaktive Parlamente anzeigen'),
          'class' => 'FacetapiFilterRewriteParliaments',
        ),
      ),
    );
}
