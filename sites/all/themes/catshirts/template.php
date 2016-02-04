<?php

/**
 * Implements hook_preprocess_follow_css().
 */
function catshirts_preprocess_follow_css(&$variables) {
  // Allow for template overrides based on style name.
  $variables['theme_hook_suggestions'][] = 'follow-css__' . $variables['icon_style_name'];

  // Load up the style array.
  //if ($style = follow_get_icon_style($variables['icon_style_name'])) {
    $variables['icon_style'] = 'paulrobertlloyd32'; //$style;
  //}

  // Normalize the selector prefix to have a single space at the end.
  if (!empty($variables['selector_prefix'])) {
    $variables['selector_prefix'] = rtrim($variables['selector_prefix']) . ' ';
  }

  // Set up the icon path.
  if (empty($variables['icon_path'])) {
    $variables['icon_path'] = _follow_style_icon_path($style);
  }

  // Convert the CSS overrides into a string.
  if (empty($variables['css_overrides']) && !empty($style['css-overrides'])) {
    $css_overrides = $variables['selector_prefix'] . "a.follow-link {\n";
    foreach ($style['css-overrides'] as $line) {
      $css_overrides .= "  $line\n";
    }
    $variables['css_overrides'] = $css_overrides . "}\n";
  }
}