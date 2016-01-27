<?php

/**
 * @file
 *
 * Filter to rewrite facet items via a dedicated hook
 *
 */
class FacetapiFilterRewriteItems1 extends FacetapiFilter {
  public function execute(array $build) {

    // Handle only ZIP-Code searches (4 or 5 digit numbers)
    $endpoint = $_GET['k'];
    if (!preg_match("@^\d{4,5}$@",$endpoint)){
      return $build;
    }

    $settings = $this->settings;
    if ($settings->facet == "field_user_constituency") {
      if (sizeof($build) == 1) {
        if (isset($_GET["f"])) {
          return $build;
        }
        return array();
      }
      foreach ($build as $key => $item) {

        $build[$key]["#html"] = TRUE;
        unset($build[$key]["#count"]);
        $vocterm = taxonomy_term_load($key);
        $location_names = array_unique(explode(",", $vocterm->field_constituency_ac_descriptor["und"]["0"]["value"]));
        $i = 0;
        foreach ($location_names as $name) {
          $exname = explode(":", $name, 2);
          if ($endpoint == $exname[0]){
            if ($i == 0) {
              $build[$key]["#markup"] = $exname[1];
            }
            else {
              $build[$key . "-" . $i] = $build[$key];
              $build[$key . "-" . $i]["#markup"] = $exname[1];
            }
            $i++;
          }
        }
      }
     
    }
    $build[0]["#html"] = TRUE;
    $build[0]["#markup"] = "</a><div class='facet-notice'>Ihre Postleitzahlensuche ergab mehr als einen Treffer, bitte wählen Sie aus der Liste bitte Ihre(n) Stadt/Stadtteil bzw. Ihren Ort/Ortsteil heraus, um in Ihren Wahlkreis zu springen.</div>";
    return $build;
  }
}

class FacetapiFilterRewriteParliaments extends FacetapiFilter {
  public function execute(array $build) {
    $settings = $this->settings;
    if ($settings->facet == "field_user_parliament") {
      foreach ($build as $key => $item) {
        if ($build[$key]['#active'] == 0){
          // Remove active parliament from link so it will show XOR behavior
          $build[$key]["#path"] = preg_replace("/\/parlament\/[\w-]+-(?!".$key.")\d+/", "", $build[$key]["#path"]);
        }
        else {
          $build[$key]["#path"] = current_path();
        }
      }
    }
    return $build;
  }
}

