[% USE raw %]
[% USE Koha %]
[% USE Branches %]
[% USE AdditionalContents %]
[%- USE KohaPlugins -%]
[% USE Asset %]
[% SET opaccredits = AdditionalContents.get( location => "opaccredits", lang => lang, library => logged_in_user.branchcode || default_branch ) %]
[% PROCESS 'html_helpers.inc' %]
[% IF Koha.Preference( 'CookieConsent' ) %]
 [% USE JSConsents %]
[% END %]
[% UNLESS ( is_popup ) %]
 [% SET OpacLangSelectorMode = Koha.Preference('OpacLangSelectorMode') %]
 [% IF ( opaccredits ) %]
 <div class="container-fluid">
 <div class="row">
 <div class="col">
 [% PROCESS koha_news_block news => opaccredits %]
 </div>
 </div>
 </div>
 [% END #/ opaccredits %]
 </div> <!-- / #wrapper in masthead.inc -->

 [% IF ( Koha.Preference('OPACReportProblem') && Koha.Preference('KohaAdminEmailAddress') ) || Koha.Preference( 'CookieConsent' ) || OpacKohaUrl %]
 <footer>
 <div class="container-fluid">
 <div class="row">
 <div class="col">
 <div id="report-koha-url">
 <div class="row justify-content-between">
 [% IF Koha.Preference('OPACReportProblem') && Koha.Preference('KohaAdminEmailAddress') || Koha.Preference( 'CookieConsent' ) %]
 <div class="col">
 <ul class="nav" id="footernav">
 [% IF Koha.Preference('OPACReportProblem') && Koha.Preference('KohaAdminEmailAddress') %]
 <li id="report_a_problem" class="nav-item noprint">
 <a href="/cgi-bin/koha/opac-reportproblem.pl">الإبلاغ عن مشكلة</a>
 </li>
 [% END %]
 [% IF Koha.Preference( 'CookieConsent' ) %]
 <li id="cookieConsentFooter" class="nav-item noprint">
 <a href="#">Cookies</a>
 </li>
 [% END %]
 </ul>
 </div>
 [% END # / IF Koha.Preference('OPACReportProblem') && Koha.Preference('KohaAdminEmailAddress') %]
 [% IF OpacKohaUrl %]
 <div class="col">
 <div id="koha_url" class="clearfix noprint">
 <p>مدعوم بواسطة [% IF template.name.match('opac-main.tt') %] <a class="koha_url" href="http://koha-community.org">كوها</a>
 [% ELSE %]
 <a class="koha_url" rel="nofollow" href="http://koha-community.org">كوها</a>
 [% END %]</p>
 </div> <!-- /#koha_url -->
 </div> <!-- /.col -->
 [% END # /IF OpacKohaUrl %]
 </div> <!-- /.row.justify-content-between -->
 </div> <!-- /#report-koha-url -->
 </div> <!-- /.col -->
 </div> <!-- /.row -->
 </div> <!-- /.container-fluid -->
 </footer>
 [% END # / OPACReportProblem || OpacKohaUrl %]

 [% IF OpacLangSelectorMode == 'both' || OpacLangSelectorMode == 'footer' %]
 [% IF ( Koha.Preference('opaclanguagesdisplay') ) %]
 [% IF ( languages_loop ) %]
 [% UNLESS ( one_language_enabled ) %]
 <footer id="changelanguage"  class="noprint">
 <ul class="nav">
 <li class="nav-item">
 <span class="navbar-text">اللغات:</span>
 </li>
 [% FOREACH languages_loo IN languages_loop %]
 [% IF ( languages_loo.group_enabled ) %]
 [% IF ( languages_loo.plural ) %]
 <li class="nav-item dropup">
 <a class="nav-link dropdown-toggle" href="#" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false" id="show[% languages_loo.rfc4646_subtag | html %]">
 [% IF ( languages_loo.native_description ) %]
 [% languages_loo.native_description | html %]
 [% ELSE %]
 [% languages_loo.rfc4646_subtag | html %]
 [% END %]
 </a><!-- /.nav-link.dropdown-toggle -->
 <div id="sub[% languages_loo.rfc4646_subtag | html %]" class="dropdown-menu" aria-labelledby="show[% languages_loo.rfc4646_subtag | html %]">
 [% FOREACH sublanguages_loo IN languages_loo.sublanguages_loop %]
 [% IF ( sublanguages_loo.enabled ) %]
 [% IF ( sublanguages_loo.sublanguage_current ) %]
 <a class="dropdown-item" href="#">[% sublanguages_loo.native_description | html %] [% sublanguages_loo.script_description | html %] [% sublanguages_loo.region_description | html %] [% sublanguages_loo.variant_description | html %] ([% sublanguages_loo.rfc4646_subtag | html %])</a>
 [% ELSE %]
 <a class="dropdown-item" href="/cgi-bin/koha/opac-changelanguage.pl?language=[% sublanguages_loo.rfc4646_subtag | uri %]"> [% sublanguages_loo.native_description | html %] [% sublanguages_loo.script_description | html %] [% sublanguages_loo.region_description | html %] [% sublanguages_loo.variant_description | html %] ([% sublanguages_loo.rfc4646_subtag | html %])</a>
 [% END %]
 [% END # / IF sublanguages_loo.enabled %]
 [% END # / FOREACH sublanguages_loo %]
 </div> <!-- /#sub[% languages_loo.rfc4646_subtag | html %] -->
 </li> <!-- /.nav-item.dropup -->
 [% ELSE %]
 [% IF ( languages_loo.group_enabled ) %]
 [% IF ( languages_loo.current ) %]
 <li class="nav-item">
 <a class="nav-link disabled" href="#" tabindex="-1" aria-disabled="true">
 [% IF ( languages_loo.native_description ) %]
 [% languages_loo.native_description | html %]
 [% ELSE %]
 [% languages_loo.rfc4646_subtag | html %]
 [% END %]
 </a> <!-- /.nav-link -->
 </li> <!-- /.nav-item -->
 [% ELSE %]
 <li class="nav-item">
 <a class="nav-link" href="/cgi-bin/koha/opac-changelanguage.pl?language=[% languages_loo.rfc4646_subtag | uri %]">
 [% IF ( languages_loo.native_description ) %]
 [% languages_loo.native_description | html %]
 [% ELSE %]
 [% languages_loo.rfc4646_subtag | html %]
 [% END %]
 </a> <!-- /.nav-link -->
 </li> <!-- /.nav-item -->
 [% END # /IF ( languages_loo.current ) %]
 [% END # / IF languages_loo.current %]
 [% END # / IF ( languages_loo.plural ) %]
 [% END # / IF ( languages_loo.group_enabled ) %]
 [% END # / FOREACH languages_loo IN languages_loop %]
 </ul> <!-- /.nav -->
 </footer> <!-- / #changelanguage -->
 [% END # / UNLESS ( one_language_enabled ) %]
 [% END # / IF ( languages_loop && opaclanguagesdisplay ) %]
 [% END # / IF opaclanguagesdisplay %]
 [% END # /IF OpacLangSelectorMode == 'both' || OpacLangSelectorMode == 'footer' %]
[% END # / UNLESS is_popup %]

[% IF Koha.Preference( 'OpacTrustedCheckout' ) %]
 [% INCLUDE 'modals/checkout.inc' %]
[% END %]

<!-- CookieConsentedJS code that may run -->
[% IF Koha.Preference( 'CookieConsent' ) && JSConsents.all('opacConsent').size %]
 [% consents = JSConsents.all('opacConsent') %]
 [% FOREACH consent IN consents %]
 <div class="consentCode" style="display:none" aria-hidden="true" data-consent-id="[% consent.id | html %]" data-consent-code="[% consent.code | html %]" data-consent-match-pattern="[% consent.matchPattern | html %]" data-consent-cookie-domain="[% consent.cookieDomain | html  %]" data-consent-cookie-path="[% consent.cookiePath | html %]" data-requires-consent="[% consent.opacConsent ? 'true' : 'false' | html %]"></div>
 [% END %]
[% END %]

<!-- JavaScript includes -->
[% Asset.js("lib/jquery/jquery-3.6.0.min.js") | $raw %]
[% Asset.js("lib/jquery/jquery-migrate-3.3.2.min.js") | $raw %]
[% Asset.js("lib/bootstrap/js/bootstrap.bundle.min.js") | $raw %]
[% Asset.js("lib/fontfaceobserver/fontfaceobserver.min.js") | $raw %]
[% Asset.js("lib/enquire/enquire.min.js") | $raw %]
<script>
    let logged_in_user_id = "[% logged_in_user.borrowernumber | html %]";
</script>
[% Asset.js("js/global.js") | $raw %]
[% IF ( OPACAmazonCoverImages || SyndeticsCoverImages ) %]
 [% Asset.js("js/amazonimages.js") | $raw %]
[% END %]

<script>
    [% IF (query_desc) %]
        var query_desc = "[% query_desc | html %]";
        var querystring = "[% querystring | html %]";
        var query_cgi = "[% query_cgi | html %]";
    [% END %]

    [% IF ( OPACAmazonCoverImages || SyndeticsCoverImages ) %]
        $(window).load(function() {
            verify_images();
         });
    [% END %]
    $(".print-large").on("click",function(){
        window.print();
        return false;
    });
    $(".addtoshelf").on("click",function(e){
        e.preventDefault();
        Dopop( this.href );
    });
    $("body").on("click", ".addtocart", function(e){
        e.preventDefault();
        var biblionumber = $(this).data("biblionumber");
        addRecord( biblionumber );
    });
    $("body").on("click", ".cartRemove", function(e){
        e.preventDefault();
        var biblionumber = $(this).data("biblionumber");
        delSingleRecord( biblionumber );
    });
    $(".clearsh").on("click", function(){
        return confirmDelete( _("هل أنت متأكد من أنك تريد حذف سجل بحثك؟") );
    });
<!-- Ahmad Nasser -->
//For OPAC redesign, EL, 1-13-20, Replace Koha logo with home icon (Added to prod 7-10-20)
$("#logo").replaceWith("<a href='/cgi-bin/koha/opac-main.pl'><i class='fa fa-home' style='color:#fff'></i>");

//Added a Font Awesome Book Icon. We're using FA 4.3.0 -EL 
top_button_convert = function() {
 var basketcount = '';
 if($('#basketcount').text()){
  basketcount = $('#basketcount').html()};
 $("#cartmenulink").html(
'<i id="carticon" class="fa fa-book"></i><span> حقيبة الكتب<span id="basketcount">' + basketcount + '</span></span>'
 );
};
 
top_button_convert(); // run once 
 
$("a.addtocart").on('click', function() {
 top_button_convert();  // run on given clicks
});

$("#userbasket h2").text("حقيبة الكتب");
if ($("#basket").length > 0){$("head title").text("HELM Catalog > حقيبة الكتب")};

   
//Move some links from the More Searches bar to nav (v21.05)
  $('#cart-list-nav').append('<li class="divider-vertical"></li><li class="nav-item dropdown"><a id="exploremenu" class="nav-link dropdown-toggle" href="#" title="Explore the catalog" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="true"><i class="fa fa-search fa-icon-white"></i><span class="listslabel"> اكتشف</span><b class="caret"></b></a><ul class="dropdown-menu" aria-labelledby="exploremenu" role="menu"><a class="dropdown-item" href="/cgi-bin/koha/opac-tags_subject.pl" tabindex="-1" role="menuitem">سحابة الموضوع</a><a class="dropdown-item" href="/cgi-bin/koha/opac-showreviews.pl" tabindex="-1" role="menuitem">أحدث التعليقات</a></ul></li><li class="divider-vertical"></li><li class="nav-item"><a id="MemberLink" class="nav-link" href="/cgi-bin/koha/opac-library.pl" title="Member Libraries" role="button"><i class="fa fa-address-book fa-icon-white"></i> <span class="memlibslabel listslabel">المكتبات اﻷعضاء</span></li>');
  $('.nav li.search_history').addClass('listslabel');
  $('#moresearches li:contains("Recent comments"),#moresearches li:contains("Most popular"),#moresearches li:contains("Libraries")').remove();
  //END Move some links from the More Searches bar to nav

/* placeholder text */
$('#muserid, #userid, #username').attr('placeholder' , 'أدخل اسم المستفيد');
$('#mpassword, #password').attr('placeholder' , 'أدخل كلمة السر');

<!-- Ahmad Nasser -->

</script>

[% IF Koha.Preference( 'opacbookbag' ) == 1 %]
 [% Asset.js("js/basket.js") | $raw %]
[% ELSIF ( Koha.Preference( 'virtualshelves' ) == 1 ) %]
 [% Asset.js("js/basket.js") | $raw %]
[% ELSE %]
 <script>var readCookie;</script>
[% END %]

[% IF Koha.Preference( 'opacuserlogin' ) == 1 %][% IF Koha.Preference( 'TagsEnabled' ) == 1 %][% Asset.js("js/tags.js") | $raw %][% END %][% END %]
[% IF ( GoogleJackets ) %]
 [% Asset.js("js/google-jackets.js") | $raw %]
[% END %]
[% IF ( Koha.Preference('OpacCoce') && Koha.Preference('CoceProviders') ) %]
 [% Asset.js("js/coce.js") | $raw %]
[% END %]

[% IF OPACLocalCoverImages %]
 [% Asset.js("js/localcovers.js") | $raw %]
[% END %]

[% IF ( BakerTaylorEnabled ) %]
 [% Asset.js("js/bakertaylorimages.js") | $raw %]
 <script>
        $(window).load(function(){
            bt_verify_images();
        });
    </script>
[% END %]

[% IF Koha.Preference( 'OpacNewsLibrarySelect' ) %]
<script>
    $("#news-branch-select").change(function() {
        $( "#news-branch-select" ).submit();
    });
</script>
[% END %]

[% Asset.js("lib/js-cookie/js.cookie-3.0.1.min.js") | $raw %]
<script>
$(document).ready(function() {
    if($('#searchsubmit').length) {
        $(document).on("click", '#searchsubmit', function(e) {
            Cookies.remove("form_serialized", { path: '/'});
            Cookies.remove("form_serialized_limits", { path: '/'});
            Cookies.remove("search_path_code", { path: '/'});
        });
    }
});
</script>
<!-- Ahmad Nasser -->
<script>
$('#patronregistration-modal, #opac-login-page #registrationinstructions').html('<ul class="fa-ul"><li><span class="fa-li-rtl"><i class="fa fa-arrow-circle-left"></i></span><a href="/cgi-bin/koha/opac-memberentry.pl"> ليس لديك بطاقة للمكتبة حتى الآن؟ سجل هنا.</a></li></ul>');
  $('#forgotpassword-modal a, #opac-login-page #forgotpassword a').wrap('<ul class="fa-ul"><li>');
  $('#forgotpassword-modal li, #opac-login-page #forgotpassword li').prepend('<span class="fa-li-rtl"><i class="fa fa-arrow-circle-left"></i></span>');
</script>

<script>
$('#opacheader').append( $('#moresearches') );
$('#moresearches ul').cleanWhitespace();
</script>
<!-- Ahmad Nasser -->
[% INCLUDE 'js-date-format.inc' %]
[% INCLUDE 'js-biblio-format.inc' %]
[% PROCESS jsinclude %]
[% IF ( Koha.Preference('OPACUserJS') ) %]
 <script>
        [% Koha.Preference('OPACUserJS') | $raw %]
    </script>
[% END %]
[% IF Branches.GetBranchSpecificJS( Branches.GetLoggedInBranchcode() || default_branch) %]
 <script>
        [% Branches.GetBranchSpecificJS( Branches.GetLoggedInBranchcode() || default_branch) | $raw %]
    </script>
[% END %]
[% IF SCO_login %]
 [% SET SCOUserJS = Koha.Preference('SCOUserJS') %]
 [% IF ( SCOUserJS ) %]
 <script>

            [% SCOUserJS | $raw %]

        </script>
 [% END %]
[% END %]
[% IF Koha.Preference( 'OpacTrustedCheckout' ) %]
 [% Asset.js("js/modals/checkout.js") | $raw %]
[% END %]
[% IF Koha.Preference( 'CookieConsent' ) %]
 [% Asset.js("js/cookieconsent.js") | $raw %]
[% END %]
[% KohaPlugins.get_plugins_opac_js | $raw %]
</body>
</html>
