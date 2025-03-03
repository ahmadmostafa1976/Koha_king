<div class="actions-menu noprint">
 [% IF Koha.Preference( 'OPACHoldRequests' ) == 1 %]
 [% UNLESS ( items.norequests ) %]
 [% IF Koha.Preference( 'opacuserlogin' ) == 1 %]
 [% IF ( shelf AND op == 'view' ) # Lists view has more granular checking of hold availability %]
 [% IF ( items.allow_onshelf_holds ) %]
 <span class="actions"><a aria-label="وضع حجز على [% items.title | html %]" class="btn btn-link btn-sm" href="/cgi-bin/koha/opac-reserve.pl?biblionumber=[% items.biblionumber | html %]"><i class="fa fa-fw fa-bookmark" aria-hidden="true"></i> احجز</a></span>
 [% ELSE %]
 [% IF ( items.itemsissued ) %]
 <span class="actions"><a aria-label="وضع حجز على [% items.title | html %]" class="btn btn-link btn-sm" href="/cgi-bin/koha/opac-reserve.pl?biblionumber=[% items.biblionumber | html %]"><i class="fa fa-fw fa-bookmark" aria-hidden="true"></i> احجز</a></span>
 [% END %]
 [% END %]
 [% ELSE %]
 <span class="actions"><a aria-label="وضع حجز على [% items.title | html %]" class="btn btn-link btn-sm" href="/cgi-bin/koha/opac-reserve.pl?biblionumber=[% items.biblionumber | html %]"><i class="fa fa-fw fa-bookmark" aria-hidden="true"></i> احجز</a></span>
 [% END %]
 [% END # / IF opacuserlogin %]
 [% END # / UNLESS items.norequests %]
 [% END # / OPACHoldRequests %]

 [% IF Koha.Preference('UseRecalls') %]
 <span class="actions"><a class="btn btn-link btn-sm recall" href="/cgi-bin/koha/opac-recall.pl?biblionumber=[% items.biblionumber | html %]"><i class="fa-solid fa-book-bookmark" aria-hidden="true"></i> وضع استدعاء</a></span>
 [% END %]

 [% IF ( Koha.Preference( 'opacuserlogin' ) == 1 ) %]
 [% IF items.artreqpossible %]
 <span class="actions"><a href="/cgi-bin/koha/opac-request-article.pl?biblionumber=[% items.biblionumber | uri %]" class="btn btn-link btn-sm"><i class="fa-solid fa-file-lines" aria-hidden="true"></i> اطلب مقالة</a></span>
 [% END %]
 [% END %]

 [% IF ( TagsInputEnabled ) %]
 [% IF ( loggedinusername ) %]
 <span class="actions"><a id="tag_add[% items.biblionumber | html %]" href="#" class="tag_add btn btn-link btn-sm"><i class="fa fa-tag" aria-hidden="true"></i> إضافة وسم</a></span>
 <div id="tagform[% items.biblionumber | html %]" class="tag_results_input form-inline" style="display:none;">
 <label for="newtag[% items.biblionumber | html %]">وسم أو أكثر جديد، مفصولة بفاصلة:</label>
 <input type="text" name="newtag[% items.biblionumber | html %]" id="newtag[% items.biblionumber | html %]" class="form-control form-control-sm newtag" maxlength="100" />
 <input class="btn btn-sm btn-primary tagbutton" name="tagbutton" title="[% items.biblionumber | html %]" type="submit" value="إضافة" />
 <a class="cancel_tag_add" id="cancel[% items.biblionumber | html %]" href="#">(تمّ)</a>
 </div>
 <span id="newtag[% items.biblionumber | html %]_status" class="tagstatus" style="display:none;">
 حالة الوسم هنا. </span>
 [% ELSE %]
 <span class="actions">
 <span class="login4tags">
 <a class="btn btn-link btn-sm loginModal-trigger" href="/cgi-bin/koha/opac-user.pl"><i class="fa fa-tag" aria-hidden="true"></i> قم بتسجيل الدخول لإضافة الوسوم</a>
 </span>
 </span>
 [% END # IF loggedinusername %]
 [% END # if TagsInputEnabled %]

 [% IF ( ( Koha.Preference( 'opacuserlogin' ) == 1 ) && loggedinusername && ( Koha.Preference( 'virtualshelves' ) == 1 ) ) %]
 [% IF ( shelf AND op == 'view' ) %]
 <span class="actions"><a href="/cgi-bin/koha/opac-addbybiblionumber.pl?biblionumber=[% items.biblionumber | uri %]" class="addtoshelf btn btn-link btn-sm"><i class="fa fa-list" aria-hidden="true"></i> حفظ في قائمة أخرى</a></span>
 [% IF can_remove_biblios %]
 <span class="actions"><a class="btn btn-link btn-sm removeitems" data-biblionumber="[% items.biblionumber | html %]" href="/cgi-bin/koha/opac-shelves.pl?op=remove_biblios&amp;shelfnumber=[% shelf.shelfnumber | html %]&amp;biblionumber=[% items.biblionumber | html %]"><i class="fa fa-remove" aria-hidden="true"></i> إزالة من هذه القائمة</a></span>
 [% END %]
 [% ELSE %]
 <span class="actions"><a class="addtoshelf btn btn-link btn-sm" href="/cgi-bin/koha/opac-addbybiblionumber.pl?biblionumber=[% items.biblionumber | html %]"><i class="fa fa-list" aria-hidden="true"></i> حفظ في القوائم</a></span>
 [% END # /IF ( shelf AND op == 'view' ) %]
 [% END # /IF Koha.Preference( 'opacuserlogin' ) %]

 [% IF Koha.Preference( 'opacbookbag' ) == 1 %]
 [% IF ( items.incart ) %]
 <span class="actions cart-actions"><a data-biblionumber="[% items.biblionumber | html %]" class="btn btn-link btn-sm addtocart cart[% items.biblionumber | html %]" href="#"><i class="fa fa-shopping-cart" aria-hidden="true"></i> في سلتك</a> <a data-biblionumber="[% items.biblionumber | html %]" class="btn btn-link btn-sm remove cartRemove cartR[% items.biblionumber | html %]" href="#">(إزالة)</a></span>
 [% ELSE %]
 <span class="actions cart-actions"><a aria-label="إضافة [% items.title | html %] إلى السلة" class="btn btn-link btn-sm addtocart cart cart[% items.biblionumber | html %]" data-biblionumber="[% items.biblionumber | html %]" href="#"><i class="fa fa-shopping-cart" aria-hidden="true"></i> إضافة إلى السلة</a> <a style="display:none;" data-biblionumber="[% items.biblionumber | html %]" class="btn btn-link btn-sm remove cartRemove cartR[% items.biblionumber | html %]" href="#">(إزالة)</a></span>
 [% END %]
 [% END # / IF opacbookbag %]
</div>
