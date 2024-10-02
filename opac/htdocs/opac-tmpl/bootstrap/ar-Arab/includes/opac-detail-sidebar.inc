[% USE raw %]
[% USE Biblio %]
<ul id="action">
 [% IF Koha.Preference( 'opacuserlogin' ) == 1 %]
 [% IF Koha.Preference( 'OPACHoldRequests' ) == 1 %]
 [% IF ( ReservableItems ) %]
 <li><a class="reserve btn btn-link btn-lg" href="/cgi-bin/koha/opac-reserve.pl?biblionumber=[% biblio.biblionumber | html %]"><i class="fa fa-fw fa-bookmark" aria-hidden="true"></i> احجز</a></li>
 [% END %]
 [% END %]
 [% END %]

 [% IF Koha.Preference('UseRecalls') %]
 <li><a class="recall btn btn-link btn-lg" href="/cgi-bin/koha/opac-recall.pl?biblionumber=[% biblio.biblionumber | html %]"><i class="fa fa-solid fa-fw fa-book-bookmark" aria-hidden="true"></i>
 وضع استدعاء</a></li>
 [% END %]

 <li><a class="print-large btn btn-link btn-lg" href="#"><i class="fa fa-fw fa-print" aria-hidden="true"></i> طباعة</a></li>

 [% IF Koha.Preference( 'opacuserlogin' ) == 1 %]
 [% IF artreqpossible %]
 <li><a class="article_request btn btn-link btn-lg" href="/cgi-bin/koha/opac-request-article.pl?biblionumber=[% biblio.biblionumber | html %]"><i class="fa fa-fw fa-file-text" aria-hidden="true"></i> اطلب مقالة</a></li>
 [% END %]
 [% END %]

 [% IF Koha.Preference( 'virtualshelves' ) == 1 %]
 [% IF ( ( Koha.Preference( 'opacuserlogin' ) == 1 ) && loggedinusername ) %]
 <li><a class="addtoshelf btn btn-link btn-lg" href="/cgi-bin/koha/opac-addbybiblionumber.pl?biblionumber=[% biblio.biblionumber | html %]"><i class="fa fa-fw fa-list" aria-hidden="true"></i> حفظ في قوائمك</a></li>
 [% END %]
 [% END %]

 [% IF Koha.Preference( 'opacbookbag' ) == 1 %]
 [% IF ( incart ) %]
 <li><a data-biblionumber="[% biblio.biblionumber | html %]" class="addtocart incart cart[% biblio.biblionumber | html %] addrecord btn btn-link btn-lg" href="#"><i class="fa fa-fw fa-shopping-cart" aria-hidden="true"></i> في سلتك</a> <a data-biblionumber="[% biblio.biblionumber | html %]" class="cartRemove cartR[% biblio.biblionumber | html %]" href="#">(إزالة)</a></li>
 [% ELSE %]
 <li><a data-biblionumber="[% biblio.biblionumber | html %]" class="addtocart cart[% biblio.biblionumber | html %] addrecord btn btn-link btn-lg" href="#"><i class="fa fa-fw fa-shopping-cart" aria-hidden="true"></i> إضافة إلى سلتك</a> <a style="display:none;" data-biblionumber="[% biblio.biblionumber | html %]" class="cartRemove cartR[% biblio.biblionumber | html %]" href="#">(إزالة)</a></li>
 [% END %]
 [% END %]

 [% IF ( suggestion ) %]
 <li><a class="suggest_for_purchase btn btn-link btn-lg" href="/cgi-bin/koha/opac-suggestions.pl?op=add_form&biblionumber=[% biblio.biblionumber | url %]"><i class="fa fa-fw fa-gift" aria-hidden="true"></i> اقترح للشراء</a></li>
 [% END %]

 [% IF Koha.Preference('OpacCatalogConcerns') %]
 <li><a class="report_a_concern btn btn-link btn-lg" href="#" data-toggle="modal" data-target="#addConcernModal"><i class="fa fa-fw fa-warning" aria-hidden="true"></i> الإبلاغ عن شكوى</a></li>
 [% END %]

 [% IF ( OpacHighlightedWords && query_desc ) %]
 <li>
 <a href="#" class="highlight_toggle btn btn-link btn-lg" id="highlight_toggle_off"><i class="fa-fw fa-solid fa-pencil" aria-hidden="true"></i> إلغاء تمييز</a>
 <a href="#" class="highlight_toggle btn btn-link btn-lg" id="highlight_toggle_on"><i class="fa-fw fa-solid fa-pencil" aria-hidden="true"></i> تمييز</a>
 </li>
 [% END %]


 [% IF ( Koha.Preference('OPACDetailQRCode' ) ) %]
 <li>
 <a class="show_qrcode btn btn-link btn-lg" href="#"><i class="fa fa-fw fa-qrcode" aria-hidden="true"></i> إرسال إلى جهاز</a>
 <div id="qrcode" class="d-none"></div>
 </li>
 [% END %]

 [% SET export_options = Koha.Preference('OpacExportOptions').split(',') %]
 [% IF export_options.size %]
 <li>
 <div id="export">
 <div class="dropdown">
 <a id="format" class="btn btn-link btn-lg dropdown-toggle" data-toggle="dropdown" href="#"><i class="fa fa-fw fa-download" aria-hidden="true"></i> حفظ التسجيلة <b class="caret"></b></a>
 <div class="dropdown-menu dropdown-menu-right" aria-labelledby="format">
 [% FOREACH option IN export_options %]
 [% IF option == 'dc' %]
 <a class="dropdown-item" href="#" data-toggle="modal" data-target="#exportModal_">دبلن كور</a>
 [% ELSE %]
 <a class="dropdown-item" href="/cgi-bin/koha/opac-export.pl?op=export&amp;bib=[% biblio.biblionumber | html %]&amp;format=[% option | html %]">
 [% SWITCH option %]
 [% CASE 'bibtex' %]<span>BIBTEX</span>
 [% CASE 'endnote' %]<span>EndNote</span>
 [% CASE 'marcxml' %]<span>MARCXML</span>
 [% CASE 'marc8' %]<span>مارك (ليس يونيكود/MARC-8)</span>
 [% CASE 'utf8' %]<span>مارك (يونيكود/UTF-8)</span>
 [% CASE 'marcstd' %]<span>مارك (Unicode/UTF-8، قياسي)</span>
 [% CASE 'mods' %]<span>MODS (XML)</span>
 [% CASE 'ris' %]<span>RIS</span>
 [% CASE 'isbd' %]<span>تدوب</span>
 [% END %]
 </a>
 [% END %]
 [% END %]
 </div> <!-- /.dropdown-menu -->
 </div> <!-- /.dropdown -->
 </div> <!-- /#export -->
 </li>
 [% END %]

 [% IF ( OPACSearchForTitleIn ) %]
 <li>
 <div id="moresearches_menu">
 <div class="dropdown">
 <a id="furthersearches" class="btn btn-link btn-lg dropdown-toggle" data-toggle="dropdown" href="#" role="button" aria-haspopup="true" aria-expanded="false">
 <i class="fa fa-fw fa-search" aria-hidden="true"></i> المزيد من البحث </a>
 <div class="dropdown-menu dropdown-menu-right" aria-labelledby="furthersearches">
 <div class="dropdown-header">البحث عن هذا العنوان في:</div>
 [% OPACSearchForTitleIn | $raw %]
 </div>
 </div>
 </div>
 </li>
 [% END %]
</ul>

<!-- Dublin Core Modal Form -->
<div class="modal" id="exportModal_" tabindex="-1" role="dialog" aria-labelledby="exportModalLabel" aria-hidden="true">
 <div class="modal-dialog">
 <div class="modal-content">
 <div class="modal-header">
 <h3 class="modal-title" id="exportModalLabel">تصدير الى دبلن كور...</h3>
 <button type="button" class="closebtn" data-dismiss="modal" aria-hidden="true">&times;</button>
 </div>
 <form method="post" action="/cgi-bin/koha/opac-export.pl">
 [% INCLUDE 'csrf-token.inc' %]
 <div class="modal-body">
 <fieldset id="dc_fieldset">
 <input id="input-simple" type="radio" name="format" value="rdfdc">
 <label class="label_dc" for="input-simple">DC-RDF بسيط</label>
 <br>
 <input id="input-oai" type="radio" name="format" value="oaidc" checked>
 <label class="label_dc" for="input-oai">OAI-DC</label>
 <br>
 <input id="input-srw" type="radio" name="format" value="srwdc">
 <label class="label_dc" for="input-srw">SRW-DC</label>
 <br>
 <input type="hidden" name="op" value="cud-export">
 <input type="hidden" name="bib" value="[% biblio.biblionumber | html %]">
 </fieldset>
 </div>
 <div class="modal-footer">
 <button type="submit" class="btn btn-primary">تصدير</button>
 <button class="btn btn-link btn-lg" data-dismiss="modal" aria-hidden="true">إلغاء</button>
 </div>
 </form>
 </div> <!-- /.modal-content -->
 </div> <!-- /.modal-dialog -->
</div> <!-- /.modal -->
