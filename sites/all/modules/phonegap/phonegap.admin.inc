<?php 
/**
 * 
 * Phone gap admin settings form
 * 
 */
function phonegap_admin_settings() {
$types = node_type_get_types();
foreach ($types as $node_type) {
$options[$node_type->type] = $node_type->name;
}; 

$form['phonegap_post_settings'] = array(
     '#type'          => 'radios',
     '#title'         => t('Select which content type will receive mobile posts '),
     '#description'   => t('Select which content type will be created when a mobile post is uploaded. Note the content type should contain a body field and a summary field.'),
     '#options'       => $options,
     '#default_value' => variable_get('phonegap_content_type','article'),
);
 
$publish = array(
      'published' => 'Posts will be published',
      'promoted'  => 'Post will be promoted to home page', 
       
);

$form['phonegap_admin_publish_settings'] = array(
     '#type'    => 'checkboxes',
     '#title'   => t('Choose whether mobile posts will be published or unpublished by default '),
     '#options' => $publish,
     '#default_value' => variable_get('phonegap_publish_content',array('published')),
);

$gapformats = filter_formats(); 
foreach ($gapformats as $gapformat) {
$goptions[$gapformat->format] = $gapformat->name;
}; 
//
$form['phonegap_format_settings'] = array(
     '#type'    => 'radios',
     '#title'   => t('Select which format type will be assigned to mobile posts '),
     '#options' => $goptions,
    '#default_value' => variable_get('phonegap_input_format','filtered_html'),
);

  $form['#submit'][] = 'phonegap_admin_settings_submit';

  return system_settings_form($form);
}

function phonegap_admin_settings_submit($form, $form_state) {
//  watchdog('phonegap','select'.$form_state['values']['phonegap_post_settings']) ;
//  
// foreach ($form_state['values']['phonegap_admin_publish_settings'] as $key => $value) {
// watchdog('phonegap','key:'.$key);
// };
 
 variable_set('phonegap_content_type',$form_state['values']['phonegap_post_settings']);
 variable_set('phonegap_input_format',$form_state['values']['phonegap_format_settings']);
 
 variable_set('phonegap_publish_content',$form_state['values']['phonegap_admin_publish_settings']);
}
