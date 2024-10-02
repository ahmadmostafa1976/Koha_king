<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
[% USE raw %]
[% USE Koha %]
[% USE Branches %]
[% USE Categories %]
[% USE AuthClient %]
[% USE AdditionalContents %]
[% PROCESS 'html_helpers.inc' %]
[% IF Koha.Preference( 'CookieConsent' ) %]
 [% USE JSConsents %]
[% END %]
[% SET OpacLangSelectorMode = Koha.Preference('OpacLangSelectorMode') %]
[% SET OpacHeader = AdditionalContents.get( location => "opacheader", lang => lang, library => logged_in_user.branchcode || default_branch, blocktitle => 0 ) %]
[% SET OpacCustomSearch = AdditionalContents.get( location => "OpacCustomSearch", lang => lang, library => logged_in_user.branchcode || default_branch, blocktitle => 0 ) %]
[% SET OpacLoginInstructions = AdditionalContents.get( location => "OpacLoginInstructions", lang => lang, library => branchcode || default_branch ) %]
[% SET OpacMoreSearches = AdditionalContents.get( location => "OpacMoreSearches", lang => lang, library => branchcode || default_branch ) %]
[% SET CookieConsentBar = AdditionalContents.get( location => "CookieConsentBar", lang => lang, library => branchcode || default_branch ) %]
[% SET CookieConsentPopup = AdditionalContents.get( location => "CookieConsentPopup", lang => lang, library => branchcode || default_branch ) %]

<button id="scrolltocontent">تخطى إلى المحتوى الرئيسي</button>
<div id="wrapper">
 <div id="header-region" class="noprint">
 <nav class="navbar navbar-expand">
 <div id="logo">
 <a class="navbar-brand" href="/cgi-bin/koha/opac-main.pl">
 [% IF ( LibraryNameTitle ) %] [% LibraryNameTitle | html %] [% ELSE %] كوها أونلاين [% END %] </a>
 </div>
 [% IF ( OpacPublic ) %]
 [% IF ( Koha.Preference( 'opacbookbag' ) == 1 ) %]
 <div id="cartDetails" class="cart-message">سلتك فارغة.</div>
 [% END %]
 <ul id="cart-list-nav" class="navbar-nav">
 [% IF ( Koha.Preference( 'opacbookbag' ) == 1 ) %]
 <li class="nav-item js-show">
 <a class="nav-link" href="#" id="cartmenulink" role="button" title="تجميع المواد التي تهمك">
 <i id="carticon" class="fa fa-shopping-cart fa-icon-black" aria-hidden="true"></i> <span class="cartlabel">السلة</span> <span id="basketcount"></span>
 </a>
 </li>
 [% END %]
 <li class="divider-vertical"></li>
 [% IF ( Koha.Preference( 'virtualshelves' ) == 1 ) %]
 <li class="nav-item dropdown">
 <a aria-expanded="false" aria-haspopup="true" aria-label="عرض القائمة المنسدلة مع معلومات القائمة التفصيلية" class="nav-link dropdown-toggle" data-toggle="dropdown" href="/cgi-bin/koha/opac-shelves.pl" id="listsmenu" role="button" title="عرض القوائم"><i class="fa fa-list fa-icon-black" aria-hidden="true"></i> <span class="listslabel">قوائم</span>
 </a>
 <div aria-labelledby="listsmenu" role="menu" class="dropdown-menu">
 [% IF some_public_shelves.count %]
 <a class="dropdown-item" href="/cgi-bin/koha/opac-shelves.pl?op=list&amp;public=1" tabindex="-1" role="menuitem"><strong>قوائم عامة</strong></a>
 [% SET number_of_public_shelves = 0 %]
 [% FOREACH s IN some_public_shelves %]
 <a class="dropdown-item" href="/cgi-bin/koha/opac-shelves.pl?op=view&amp;shelfnumber=[% s.shelfnumber | uri %]&amp;sortfield=[% s.sortfield | uri %]" tabindex="-1" role="menuitem">[% s.shelfname | html %]</a>
 [% SET number_of_public_shelves = number_of_public_shelves + 1 %]
 [% IF number_of_public_shelves >= 10 %][% LAST %][% END %]
 [% END %]
 [% IF some_public_shelves > 10 %]
 <a class="dropdown-item listmenulink" href="/cgi-bin/koha/opac-shelves.pl?op=list&amp;public=1" tabindex="-1" role="menuitem">عرض الكل</a>
 [% END %]
 [% END %]
 [% IF some_public_shelves.count > 0 %]
 <div class="dropdown-divider"></div>
 [% END %]
 [% IF Koha.Preference( 'opacuserlogin' ) == 1 %]
 <a class="dropdown-item" href="/cgi-bin/koha/opac-shelves.pl?op=list&amp;public=0" tabindex="-1" role="menuitem"><strong>قوائمك</strong></a>
 [% IF loggedinusername %]
 [% IF some_private_shelves.count %]
 [% SET number_of_private_shelves = 0 %]
 [% FOREACH s IN some_private_shelves %]
 <a class="dropdown-item" href="/cgi-bin/koha/opac-shelves.pl?op=view&amp;shelfnumber=[% s.shelfnumber | uri %]&amp;sortfield=[% s.sortfield | uri %]" tabindex="-1" role="menuitem">[% s.shelfname | html %]</a>
 [% SET number_of_private_shelves = number_of_private_shelves + 1 %]
 [% IF number_of_private_shelves >= 10 %][% LAST %][% END %]
 [% END %]
 [% IF some_private_shelves > 10 %]
 <a class="dropdown-item listmenulink" href="/cgi-bin/koha/opac-shelves.pl?op=list&amp;public=0" tabindex="-1" role="menuitem">عرض الكل</a>
 [% END %]
 [% ELSE %]
 <a class="dropdown-item disabled" href="#" tabindex="-1" role="menuitem">لا توجد قوائم خاصة</a>
 [% END %]
 <a class="dropdown-item listmenulink" href="/cgi-bin/koha/opac-shelves.pl?op=add_form" tabindex="-1" role="menuitem">قائمة جديدة</a>
 [% ELSE %]
 <a class="dropdown-item" href="/cgi-bin/koha/opac-shelves.pl?op=add_form" tabindex="-1" role="menuitem">قم بتسجيل الدخول لإنشاء قوائمك الخاصة</a>
 [% END # / IF loggedinusername %]
 [% END # / IF opacuserlogin %]
 </div> <!-- / .dropdown-menu -->
 </li> <!-- / .nav-item.dropdown -->
 [% END # / IF virtualshelves %]
 [% IF Koha.Preference( 'OpacTrustedCheckout' ) %]
 <li class="nav-item">
 <a class="nav-link" data-target="#checkoutModal" data-toggle="modal" href="#" id="comenulink" role="button" title="إعارة ذاتية">
 <i id="checkout-icon" class="fa fa-barcode fa-icon-black" aria-hidden="true"></i> <span class="checkout-label">إعارة ذاتية</span>
 </a>
 </li>
 [% END %]

 </ul> <!-- / .navbar-nav -->
 [% END # /IF OpacPublic %]
 [% IF Koha.Preference( 'opacuserlogin' ) == 1 ||  Koha.Preference( 'EnableOpacSearchHistory') || Koha.Preference( 'opaclanguagesdisplay' ) %]
 [% IF ( Koha.Preference( 'opaclanguagesdisplay' ) ) %]
 [% INCLUDE 'masthead-langmenu.inc' %]
 [% END %]
 <ul id="members" class="navbar-nav">
 <li class="nav-item dropdown">
 [% IF ( Koha.Preference( 'opacuserlogin' ) == 1 ) %]
 [% IF ( loggedinusername ) %]
 <a href="/cgi-bin/koha/opac-user.pl" class="dropdown-toggle" id="user-menu" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false">
 <i class="fa fa-user fa-icon-black fa-fw" aria-hidden="true"></i>
 <span class="userlabel">مرحـبـاً [% INCLUDE 'patron-title.inc' patron = logged_in_user no_html = 1 %]</span>
 </a>
 <a tabindex="-1" role="menuitem" class="logout js-hide" href="/cgi-bin/koha/opac-main.pl?logout.x=1"><i class="fa fa-fw fa-sign-out" aria-hidden="true"></i> خروج</a>
 [% ELSE %]
 [% IF Koha.Preference('casAuthentication') %]
 [%# CAS authentication is too complicated for modal window %]
 <a class="nav-link login-link" href="/cgi-bin/koha/opac-user.pl"><i class="fa fa-user fa-icon-black fa-fw" aria-hidden="true"></i> <span class="userlabel">تسجيل الدخول إلى حسابك</span></a>
 [% ELSIF ( Koha.Preference('GoogleOpenIDConnect') == 1 ) %]
 <a href="/cgi-bin/koha/svc/auth/googleopenidconnect" class="nav-link login-link loginModal-trigger"><i class="fa fa-user fa-icon-black fa-fw" aria-hidden="true"></i> <span class="userlabel">تسجيل الدخول إلى حسابك</span></a>
 [% ELSE %]
 <a href="/cgi-bin/koha/opac-user.pl" class="nav-link login-link loginModal-trigger"><i class="fa fa-user fa-icon-black fa-fw" aria-hidden="true"></i> <span class="userlabel">تسجيل الدخول إلى حسابك</span></a>
 [% END %]
 [% END %]
 [% END %]

 [% IF ( Koha.Preference( 'opacuserlogin' ) == 1 && loggedinusername ) %]
 <div aria-labelledby="user-menu" role="menu" class="dropdown-menu dropdown-menu-right">
 <div id="loggedinuser-menu">
 <p>
 <a class="login-link" href="/cgi-bin/koha/opac-user.pl"><span class="loggedinusername" data-borrowernumber="[% logged_in_user.borrowernumber | html %]" data-branchcode="[% logged_in_user.branchcode | html %]" data-categorycode="[% logged_in_user.categorycode | html %]">حسابك</span></a>
 </p>
 [% IF Koha.Preference( 'EnableOpacSearchHistory' ) %]
 <p>
 <a class="login-link" href="/cgi-bin/koha/opac-search-history.pl" role="menuitem" tabindex="-1" title="عرض سجل بحثك">سِجل البحث</a>
 <span class="divider-vertical"></span>
 <a class="clearsh" href="/cgi-bin/koha/opac-search-history.pl?action=delete" title="حذف سِجل بحثك"><i class="fa fa-trash-can" aria-hidden="true"></i> مسح</a>
 </p>
 [% END %]
 <a tabindex="-1" role="menuitem" class="logout" id="logout" href="/cgi-bin/koha/opac-main.pl?logout.x=1">خروج</a>
 </div>
 </div>
 [% END %]
 </li>
 <!-- Cookie consent button for non logged-in users -->
 [% IF !loggedinusername %]
 <li style="display:none" id="cookieConsentDivider" class="divider-vertical" aria-hidden="true"></li>
 <li style="display:none" id="cookieConsentLi" class="nav-item" aria-hidden="true">
 <a class="nav-link" href="#" id="cookieConsentButton" name="Your cookies" role="button" title="عرض وتعديل ملفات تعريف الارتباط التي وافقت عليها">
 <i class="fa fa-cookie-bite" aria-hidden="true"></i>
 <span class="cookieconsentlabel">ملفات تعريف الارتباط الخاصة بك</span>
 </a>
 </li>
 [% END %]
 [% IF OpacPublic && ( !Koha.Preference( 'opacuserlogin') || !loggedinusername ) %]
 [% IF Koha.Preference( 'EnableOpacSearchHistory' ) %]
 <li class="divider-vertical"></li>
 <li class="nav-item search_history">
 <a class="nav-link login-link" href="/cgi-bin/koha/opac-search-history.pl" title="عرض سجل بحثك">سِجل البحث</a>
 </li>
 <li class="divider-vertical"></li>
 <li class="nav-item">
 <a class="nav-link logout clearsh" href="/cgi-bin/koha/opac-search-history.pl?action=delete" title="حذف سِجل بحثك"><i class="fa fa-trash-can" aria-hidden="true"></i> مسح</a>
 </li>
 [% END %]
 [% END %]
 </ul>
 [% END # IF opacuserlogin || EnableOpacSearchHistory || opaclanguagesdisplay %]
 </nav> <!-- /navbar -->

 [% IF ( OpacHeader ) %]
 <div class="container-fluid">
 <div class="row">
 <div class="col">
 [% PROCESS koha_news_block news => OpacHeader %]
 </div>
 </div>
 </div>
 [% END %]

 </div> <!-- / header-region -->

 [% IF ( OpacPublic ) %]
 <div class="container-fluid">
 [% UNLESS ( advsearch ) %]
 <div class="row">
 <div class="col">
 <div id="opac-main-search" class="mastheadsearch">
 [% IF ( OpacCustomSearch ) %]
 [% PROCESS koha_news_block news => OpacCustomSearch %]
 [% ELSE %]
 <form name="searchform" method="get" action="/cgi-bin/koha/opac-search.pl" id="searchform">
 <div class="form-row align-items-center">
 <div class="col-sm-auto order-2 order-sm-2">
 <select name="idx" id="masthead_search" class="form-control">
 [% IF ( ms_kw ) %]
 <option selected="selected" value="">فهرس المكتبة</option>
 [% ELSE %]
 <option value="">فهرس المكتبة</option>
 [% END # /ms_kw %]
 [% IF ( ms_ti ) %]
 <option selected="selected" value="ti">عنوان</option>
 [% ELSE %]
 <option value="ti">عنوان</option>
 [% END # /ms_ti %]
 [% IF ( ms_au ) %]
 <option selected="selected" value="au">المؤلف</option>
 [% ELSE %]
 <option value="au">المؤلف</option>
 [% END # /ms_au%]
 [% IF ( ms_su ) %]
 <option selected="selected" value="su">الموضوع</option>
 [% ELSE %]
 <option value="su">الموضوع</option>
 [% END # /ms_su %]
 [% IF ( ms_nb ) %]
 <option selected="selected" value="nb">ردمك</option>
 [% ELSE %]
 <option value="nb">ردمك</option>
 [% END # /ms_nb%]
 [% IF ( ms_ns ) %]
 <option selected="selected" value="ns">تدمد</option>
 [% ELSE %]
 <option value="ns">تدمد</option>
 [% END # /ms_ns%]
 [% IF ( ms_se ) %]
 <option selected="selected" value="se">السلاسل</option>
 [% ELSE %]
 <option value="se">السلاسل</option>
 [% END # /ms_se %]
 [% IF ( Koha.Preference('OPACNumbersPreferPhrase') ) %]
 [% IF ( ms_callnumcommaphr ) %]
 <option selected="selected" value="callnum,phr">رقم الاستدعاء</option>
 [% ELSE %]
 <option value="callnum,phr">رقم الاستدعاء</option>
 [% END #/ms_callnumcommaphr %]
 [% ELSE %]
 [% IF ( ms_callnum ) %]
 <option selected="selected" value="callnum">رقم الاستدعاء</option>
 [% ELSE %]
 <option value="callnum">رقم الاستدعاء</option>
 [% END # /ms_callnum %]
 [% END # /IF OPACNumbersPreferPhrase %]
 </select>
 </div> <!-- /.col-sm-auto -->

 <div class="col order-4 order-sm-3">
 [% IF ( !Koha.Preference( 'OpacAddMastheadLibraryPulldown' ) == 1 && mylibraryfirst ) %]
 <input class="transl1 form-control form-control-filtered" data-placement="top" data-toggle="tooltip" id="translControl1" name="q" title="جاري البحث في  [% Branches.GetName( mylibraryfirst ) | html %] فقط" type="text" value="[% ms_value | html %]" /><span id="translControl"></span>
 [% ELSE %]
 <input type="text" class="transl1 form-control" id="translControl1" name="q" placeholder="ابحث في القاعدة" value="[% ms_value | html %]" /><span id="translControl"></span>
 [% END # /ms_value %]
 </div> <!-- /.col -->

 [% IF ( Koha.Preference( 'OpacAddMastheadLibraryPulldown' ) == 1 ) %]
 <div class="col-sm col-md-3 col-lg-2 order-3 order-sm-4">
 <select name="limit" id="select_library" class="form-control">
 <option value="">كل المكتبات</option>

 [% IF LibrarySearchGroups %]<optgroup label="المكتبات">[% END %]

 [% FOREACH library IN Branches.all( selected => opac_name ) %]
 [% NEXT UNLESS library.public %]
 [% IF library.selected %]
 <option selected="selected" value="branch:[% library.branchcode | html %]">[% library.branchname | html %]</option>
 [% ELSE %]
 <option value="branch:[% library.branchcode | html %]">[% library.branchname | html %]</option>
 [% END %]
 [% END %]

 [% IF LibrarySearchGroups %]
 </optgroup>
 <optgroup label="مجموعات">
 [% FOREACH lsg IN LibrarySearchGroups %]
 [% IF 'multibranchlimit-' _ lsg.id == opac_name || lsg.id == opac_name %]
 <option selected="selected" value="multibranchlimit:[% lsg.id | html %]">[% lsg.title | html %]</option>
 [% ELSE %]
 <option value="multibranchlimit:[% lsg.id | html %]">[% lsg.title | html %]</option>
 [% END # / bc.selected %]
 [% END %]
 </optgroup>
 [% END # / BranchCategoriesLoop %]
 </select> <!-- /#select_library -->
 </div> <!-- /.col-sm-auto -->
 [% ELSE %]
 [% IF ( opac_limit_override ) %]
 [% IF ( opac_search_limit ) %]
 [% IF ( multibranchlimit = opac_search_limit.match( 'branch:multibranchlimit-(\d+)' ) ) %]
 <input name="limit" value="multibranchlimit:[% multibranchlimit.0 | html %]" type="hidden" />
 [% ELSE %]
 <input name="limit" value="[% opac_search_limit | html %]" type="hidden" />
 [% END %]
 [% END %]
 [% ELSE %]
 [% IF ( mylibraryfirst ) %]
 <input name="limit" value="branch:[% mylibraryfirst | html %]" type="hidden" />
 [% END %]
 [% END # / opac_limit_override %]
 [% END # / OpacAddMastheadLibraryPulldown %]

 <div class="order-5 col-sm-auto">
 <button type="submit" id="searchsubmit" class="btn btn-primary" style="height: 45px;">ابحث الآن</button>
 <!--<button aria-label="بحث" class="btn btn-primary" id="searchsubmit" title="بحث" type="submit"> -->
 <!--<i class="fa fa-search" aria-hidden="true"></i> -->
 </button>
 </div>

 </div> <!-- /.form-row -->
 <input type="hidden" name="weight_search" value="1">
 </form>
 [% END # / ( OpacCustomSearch ) %]
 </div><!-- /#opac-main-search -->
 </div> <!-- /.col -->
 </div> <!-- /.row -->
 [% END # / UNLESS advsearch %]

 <div class="row">
 <ul class="nav" id="moresearches">
 <li class="nav-item">
 <i class="fa fa-search-plus" aria-hidden="true" style="color:#31708f !important"></i>  <a href="/cgi-bin/koha/opac-search.pl">بحث متقدم</a>
 </li>
 [% IF ( Koha.Preference( 'UseCourseReserves' ) == 1 ) %]
 <li class="nav-item">
 <a href="/cgi-bin/koha/opac-course-reserves.pl">الحجز الأكاديمي</a>
 </li>
 [% END %]
 [% IF Koha.Preference( 'OpacBrowser' ) == 1 %]
 <li class="nav-item">
 <a href="/cgi-bin/koha/opac-browser.pl">تصفح هرمي</a>
 </li>
 [% END %]
 [% IF Koha.Preference( 'OpacAuthorities' ) == 1 %]
 <li class="nav-item">
 <i class="fa fa-check" aria-hidden="true" style="color:#31708f !important"></i>  <a href="/cgi-bin/koha/opac-authorities-home.pl">بحث الاستناد</a>
 </li>
 [% END %]
 [% IF ( ( Koha.Preference( 'opacuserlogin' ) == 1 ) && ( Koha.Preference( 'OPACComments' ) == 1 ) && ( Koha.Preference( 'OpacShowRecentComments' ) == 1 ) ) %]
 <li class="nav-item">
 <a href="/cgi-bin/koha/opac-showreviews.pl">أحدث التعليقات</a>
 </li>
 [% END %]
 [% IF Koha.Preference( 'TagsEnabled' ) == 1 %]
  <!-- <li class="nav-item">
 <a href="/cgi-bin/koha/opac-tags.pl">سحابة الوسوم</a>
 </li> -->
 [% END %]
 [% IF Koha.Preference( 'OpacCloud' ) == 1 %]
 <li class="nav-item">
 <a href="/cgi-bin/koha/opac-tags_subject.pl">سحابة الموضوع</a>
 </li>
 [% END %]
 [% IF Koha.Preference( 'OpacTopissue' ) == 1 %]
 <li class="nav-item">
 <a href="/cgi-bin/koha/opac-topissues.pl">الأكثر شعبية</a>
 </li>
 [% END %]
 [% IF Koha.Preference('SearchEngine') == 'Elasticsearch' && Koha.Preference( 'OpacBrowseSearch' ) == 1 %]
 <li class="nav-item">
 <a href="/cgi-bin/koha/opac-browse.pl">استعراض البحث</a>
 </li>
 [% END %]
 [% IF suggestion %]
 [% IF Koha.Preference( 'AnonSuggestions' ) == 1 || Koha.Preference( 'OPACViewOthersSuggestions' ) == 1 %]
 <li class="nav-item">
 <a href="/cgi-bin/koha/opac-suggestions.pl?suggested_by_anyone=1">مقترحات الشراء</a>
 </li>
 [% END %]
 [% END %]
 <!-- <li class="nav-item">
 <a id="library_page" href="/cgi-bin/koha/opac-library.pl">
 [% IF ( singleBranchMode ) %]
 <span>مكتبة</span>
 [% ELSE %]
 <span>المكتبات</span>
 [% END %]
 </a>
 </li> -->
 [% PROCESS koha_news_block news => OpacMoreSearches %]
 </ul> <!-- /.nav#moresearches -->
 </div> <!-- /.row -->
 </div> <!-- /.container-fluid -->
 [% END # / OpacPublic %]

 <!-- Login form hidden by default, used for modal window -->
 <div id="loginModal" class="modal" tabindex="-1" role="dialog" aria-labelledby="modalLoginLabel" aria-hidden="true">
 <div class="modal-dialog">
 <div class="modal-content">
 <div class="modal-header">
 <h2 class="modal-title" id="modalLoginLabel">تسجيل الدخول إلى حسابك</h2>
 <button aria-label="إغلاق" class="closebtn" data-dismiss="modal" type="button">
 <span aria-hidden="true">&times;</span>
 </button>
 </div>
 <form action="/cgi-bin/koha/opac-user.pl" method="post" name="auth" id="modalAuth">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="has-search-query" id="has-search-query" value="" />
 <div class="modal-body">
 [% IF ( Koha.Preference('GoogleOpenIDConnect') == 1 ) %]
 <a href="/cgi-bin/koha/svc/auth/googleopenidconnect" class="btn btn-light" id="openid_connect"><i class="fa-brands fa-google" aria-hidden="true"></i> تسجيل الدخول باستخدام جوجل</a>
 <p>إذا لم يكن لديك حساب جوجل، لكن يوجد لديك حساب محلي، لا يزال بإمكأنك تسجيل الدخول: </p>
 [% END # /IF GoogleOpenIDConnect %]
 [% IF ( shibbolethAuthentication ) %]
 [% IF ( invalidShibLogin ) %]
 <!-- This is what is displayed if shibboleth login has failed to match a koha user -->
 <div class="alert alert-info">
 <p>عذرا، هوية Shibboleth الخاصة بك لا تطابق هوية مكتبة صحيحة. إذا كان لديك تسجيل دخول محلي، يمكنك استخدامه أدناه.</p>
 </div>
 [% ELSE %]
 <h3 class="shib_title">تسجيل دخول Shibboleth</h3>
 <p><a id="shib_url" class="shib_url" href="[% shibbolethLoginUrl | $raw %]">تسجيل الدخول باستخدام حساب Shibboleth</a>.</p>
 [% UNLESS Koha.Preference('opacShibOnly') %]
 <h3 class="shib_local_title">تسجيل دخول محلي</h3>
 [% END %]
 [% END %]
 [% END %]
 [% UNLESS Koha.Preference('opacShibOnly') %]
 [% SET identity_providers = AuthClient.get_providers('opac') %]
 [% IF ( ! identity_providers.empty ) %]
 [% FOREACH provider IN identity_providers %]
 <p class="clearfix">
 <a href="[% provider.url | url %]" class="btn btn-light col-md-12" id="provider_[% provider.code | html %]">
 [% IF provider.icon_url %]
 <img src="[% provider.icon_url | url %]" />
 [% ELSE %]
 <i class="fa fa-user" aria-hidden="true"></i>
 ‫[% END %] تسجيل الدخول باستخدام [% provider.description | html %] </a>
 </p>
 [% END %]
 <hr/>
 <p>إذا لم يكن لديك حساب خارجي، ولكن لديك حساب محلي، فلا يزال بإمكانك تسجيل الدخول: </p>
 [% END # /IF  identity_providers.size %]
 <input type="hidden" name="koha_login_context" value="opac" />
 <fieldset class="brief">
 <div class="local-login">
 <label for="muserid">تسجيل الدخول:</label><input type="text" id="muserid" name="login_userid" autocomplete="off" />
 <label for="mpassword">كلمة المرور:</label><input type="password" id="mpassword" name="login_password" autocomplete="off" />
 <fieldset class="action">
 <input type="hidden" name="op" value="cud-login" />
 <input class="btn btn-primary" type="submit" value="تسجيل الدخول" />
 </fieldset>
 </div>
 [% IF OpacLoginInstructions %]
 <div id="nologininstructions-modal" class="nologininstructions">
 [% PROCESS koha_news_block news => OpacLoginInstructions %]
 </div>
 [% END %]
 [% IF Koha.Preference('OpacPasswordChange') && Categories.can_any_reset_password %]
 <div id="forgotpassword-modal" class="forgotpassword">
 <p><a href="/cgi-bin/koha/opac-password-recovery.pl">نسيت كلمة مرورك؟</a></p>
 </div>
 [% END %]
 [% IF Koha.Preference('PatronSelfRegistration') && Categories.all( categorycode => Koha.Preference('PatronSelfRegistrationDefaultCategory') ).count %]
 <div id="patronregistration-modal" class="patronregistration">
 <p><a href="/cgi-bin/koha/opac-memberentry.pl">إنشاء حساب</a></p>
 </div>
 [% END %]
 </fieldset>
 [% END %]
 </div>
 </form> <!-- /#auth -->
 </div> <!-- /.modal-content -->
 </div> <!-- /.modal-dialog -->
 </div> <!-- /#modalAuth -->
 [% IF Koha.Preference( 'CookieConsent' ) %]
 <!-- Cookie consent bar -->
 <div id="cookieConsentBar" aria-hidden="true">
 [% IF ( CookieConsentBar ) %]
 <div id="cookieConsentBar_content">
 [% PROCESS koha_news_block news => CookieConsentBar %]
 </div>
 [% END %]
 <div class="consentButtons">
 [% IF ( JSConsents.all('opacConsent').size ) %]
 <button type="button" class="btn btn-primary consentAcceptAll">قبول جميع ملفات تعريف الارتباط</button>
 [% END %]
 <button type="button" class="btn btn-primary consentAcceptEssential">Accept essential cookies</button>
 <button aria-label="انقر لعرض المزيد من المعلومات حول موافقات ملفات تعريف الارتباط الخاصة بك" class="btn btn-info" id="consentMoreInfo" type="button">المزيد من المعلومات</button>
 </div>
 </div> <!-- /#cookieConsentBar -->
 <!-- Cookie consent modal -->
 <div id="cookieConsentModal" class="modal" tabindex="-1" role="dialog" aria-labelledby="cookieConsentModalLabel" aria-hidden="true">
 <div class="modal-dialog">
 <div class="modal-content">
 <div class="modal-header">
 <h2 class="modal-title" id="cookieConsentModalLabel">Cookies policy</h2>
 </div>
 <div class="modal-body">
 [% IF ( CookieConsentPopup ) %]
 <div id="cookieConsentPopupText">
 [% PROCESS koha_news_block news => CookieConsentPopup %]
 </div>
 [% END %]
 <div id="consentCookieList">
 [% consents = JSConsents.all('opacConsent') %]
 [% FOREACH consent IN consents %]
 <div class="consentModalItem">
 <div class="consentItemCheckbox">
 <input aria-label="الموافقة على ملف تعريف الارتباط" class="consentCheckbox" name="consentCheckbox" type="checkbox" value="[% consent.id | html %]">
 </div>
 <div class="consentItemMeta">
 <div class="consentItemName">[% consent.name | html %]</div>
 <div class="consentItemDescription">[% consent.description | html %]</div>
 </div>
 </div>
 [% END %]
 </div>
 </div>
 <div class="modal-footer">
 <div class="consentButtons">
 <button type="button" class="btn btn-primary consentAcceptEssential">Accept essential cookies</button>
 [% IF ( JSConsents.all('opacConsent').size ) %]
 <button type="button" class="btn btn-primary consentAcceptAll">قبول جميع ملفات تعريف الارتباط</button>
 <button type="button" class="btn btn-warning" id="consentAcceptSelected">قبول ملفات تعريف الارتباط غير الأساسية المحددة</button>
 [% END %]
 <a type="button" href="#" class="btn btn-secondary consentCloseModal">إلغاء</a>
 </div>
 </div>
 </div> <!-- /.modal-content -->
 </div> <!-- /.modal-dialog -->
 </div> <!-- /#cookieConsentModal -->
 [% END %]
