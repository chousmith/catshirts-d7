var qscbc = 0;
var qscac = 0;
var csrunonce = false;
(function ($) {
	function catshirt_rollovers(rows) {
		rows.addClass('hello').unbind('mouseenter.cs').bind('mouseenter.cs', function() {
			$(this).addClass('over');
		}).unbind('mouseleave.cs').bind('mouseleave.cs', function () {
			$(this).removeClass('over');
		});
	}
	Drupal.behaviors.catshirts = {
		attach: function (context, settings) {
			$QSC.bind('beforeQuicksandAnimation',function() {
				csrunonce = true;
			}).bind('afterQuicksandAnimation',function() {
				if ( csrunonce ) {
					catshirt_rollovers($QSC.find('.views-row'));
				}
				csrunonce = false;
			});
			
			catshirt_rollovers($('.views-row', context));
			
			$('.tabs', context).each(function() {
				if ( $(this).children().size() == 0 ) {
					$(this).remove();
				}
			});
		}
	};

})(jQuery);