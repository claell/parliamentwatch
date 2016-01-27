/**
 * @license Copyright (c) 2003-2013, CKSource - Frederico Knabben. All rights reserved.
 * For licensing, see LICENSE.html or http://ckeditor.com/license
 */

// Register a templates definition set named "default".
CKEDITOR.addTemplates( 'default', {
	// The name of sub folder which hold the shortcut preview images of the
	// templates.
	imagesPath: CKEDITOR.getUrl( CKEDITOR.plugins.getPath( 'templates' ) + 'templates/images/' ),

	// The templates definitions.
	templates: [
    	{
    		title: 'Floatbox',
    		image: 'template1.gif',
    		description: 'A floating box on the left with headline.',
    		html: '<div class="floatbox floatbox-left">' +
    			'<h3>' +
                    'Title goes here' +
    			'</h3>' +
    			'<h4>' +
                        'Subtitle goes here' +
    			'</h4>' +
    			'<ul>' +
                    '<li>List item 1</li>' +
                    '<li>List item 2</li>' +
                    '<li>List item 3</li>' +
    			'</ul>' +
    			'</div>'
    	},
		{
    		title: 'Floatbox',
    		image: 'template4.gif',
    		description: 'A floating box on the right with headline.',
    		html: '<div class="floatbox floatbox-right">' +
    			'<h3>' +
                    'Title goes here' +
    			'</h3>' +
    			'<h4>' +
                        'Subtitle goes here' +
    			'</h4>' +
    			'<ul>' +
                    '<li>List item 1</li>' +
                    '<li>List item 2</li>' +
                    '<li>List item 3</li>' +
    			'</ul>' +
    			'</div>'
    	},
		{
    		title: 'Image container with ©opyright',
    		image: 'template1.gif',
    		description: 'A container with an image and a subline floating to the left.',
    		html: '<div class="file-image float-left">' +
                    '<img src="/sites/all/modules/contrib/ckeditor/ckeditor/plugins/templates/templates/images/template1.gif">' +
                    '<div class="copyright">©opyright</div>' +
    			'</div>'
    	},
		{
    		title: 'Image container with ©opyright',
    		image: 'template4.gif',
    		description: 'A container with an image and a subline floating to the right.',
    		html: '<div class="file-image float-right">' +
                    '<img src="/sites/all/modules/contrib/ckeditor/ckeditor/plugins/templates/templates/images/template4.gif">' +
                    '<div class="copyright">©opyright</div>' +
    			'</div>'
    	}
	]
});