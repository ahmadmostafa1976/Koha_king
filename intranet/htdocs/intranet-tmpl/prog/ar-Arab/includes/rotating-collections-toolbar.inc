<div id="toolbar" class="btn-toolbar">
 <div class="btn-group">
 <a class="btn btn-default" href="/cgi-bin/koha/rotating_collections/editCollections.pl?op=new"><i class="fa fa-plus"></i> مجموعة جديدة</a>
 </div>

 [% IF ( colId ) %]
 <div class="btn-group">
 <a class="btn btn-default" href="/cgi-bin/koha/rotating_collections/transferCollection.pl?colId=[% colId | html %]"><i class="fa-solid fa-right-left"></i> النقل</a>
 </div>
 <div class="btn-group">
 <a class="btn btn-default" href="/cgi-bin/koha/rotating_collections/editCollections.pl?op=edit&amp;colId=[% colId | html %]"><i class="fa-solid fa-pencil" aria-hidden="true"></i> تحرير</a>
 </div>
 <div class="btn-group">
 <form method="post" action="/cgi-bin/koha/rotating_collections/editCollections.pl">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-delete">
 <input type="hidden" name="colId" value="[% colId | html %]">
 <button type="submit" class="btn btn-default confirmdelete"><i class="fa fa-trash-can"></i> حذف</button>
 </form>
 </div>
 [% END %]
</div>
