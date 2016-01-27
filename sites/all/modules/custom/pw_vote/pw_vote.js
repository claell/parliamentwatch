// handles onclick which sets filter
(function ($) {
  Drupal.behaviors.pwVoteFilter = {
    attach: function (context, settings) {
      $('a[rel^=filter-]').click(function(e){
        e.preventDefault();
        var filter = $(this).attr('rel').split('--');
        // var fractions = filter[1].split('/');
        var fraction = filter[1];
        var vote = filter[2];
        $('#edit-search-api-views-fulltext').val('');
        $('#edit-field-vote-user-field-user-fraction option').attr('selected', false);
        $('#edit-field-vote-user-field-user-fraction option:contains(' + fraction + ')').attr('selected', 'selected');
        // $.each(fractions, function(index, fraction){
          // $('#edit-field-vote-user-field-user-fraction option:contains(' + fraction + ')').attr('selected', 'selected');
        // });
        // $('#edit-ss-vote-user-vote-text input').attr('checked', false);
        // $('#edit-ss-vote-user-vote-text label:contains(' + vote + ')').parent().children('input').attr('checked', 'checked');
        $('#edit-field-vote option').attr('selected', false);
        $('#edit-field-vote option:contains(' + vote + ')').attr('selected', 'selected');
        $('#edit-submit-vote-search').click();
        $("#pw_vote_positions")[0].scrollIntoView({behavior: 'smooth'});
      });
    }
  };
}(jQuery));
