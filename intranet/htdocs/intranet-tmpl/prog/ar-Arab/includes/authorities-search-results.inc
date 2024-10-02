[% USE raw %]
[% BLOCK showreference %]
[%# Parameters: %]
[%# heading: the heading itself %]
[%# linkType: currently 'seefrom' or 'seealso', controls the label for the entry type: %]
[%# authid: if it is a linked authority, its authid %]

 [% SET authidurl = '/cgi-bin/koha/authorities/detail.pl?authid=' %]
 [% SET searchurl = '/cgi-bin/koha/authorities/authorities-home.pl?op=do_search&type=intranet&marclist=any&operator=contains&orderby=HeadingAsc&value=' %]

 [% IF marcflavour == 'UNIMARC' %]
 [% IF authid %]
 [% link = BLOCK %]<a href="[% authidurl _ authid | url %]">[% heading | html %]</a>[% END %]
 [% ELSE %]
 [% link = BLOCK %][% heading | html %][% END %]
 [% END %]
 [% SWITCH type %]
 [% CASE 'broader' %]
 <span class="BT"><abbr title="مصطلح أشمل">مصطلح أشمل</abbr>: [% link | $raw %]</span>
 [% CASE 'narrower' %]
 <span class="NT"><abbr title="مصطلح أضيق">مصطلح أضيق</abbr>: [% link | $raw %]</span>
 [% CASE 'seefrom' %]
 <span class="UF"><abbr title="يستخدم لـ">يستخدم لـ</abbr>: [% link | $raw %]</span>
 [% CASE 'seealso' %]
 <span class="RT"><abbr title="مصطلح ذو صلة">مصطلح ذو صلة</abbr>: [% link | $raw %]</span>
 [% END %]
 [% ELSE %]
 <span class="heading">
 [% IF ( linkType=='seealso' ) %]
 [% IF ( authid ) %]
 <a href="[% authidurl | url %][% authid | uri %]">[% heading | html %]</a>
 [% ELSE %]
 <a href="[% searchurl | url %][% heading | uri %]">[% heading | html %]</a>
 [% END %]
 [% ELSE %]
 [% heading | html %]
 [% END %]
 </span>
 [% UNLESS ( type=='seefrom' || type=='seealso' ) %]
 <span class="type">
 [% SWITCH type %]
 [% CASE 'earlier' %]<span>(رأس سابق)</span>
 [% CASE 'later' %]<span>(رأس لاحق)</span>
 [% CASE 'acronym' %]<span>(اختصار عبارة)</span>
 [% CASE 'musical' %]<span>(قطعة موسيقية)</span>
 [% CASE 'broader' %]<span>(عنوان أوسع)</span>
 [% CASE 'narrower' %]<span>(عنوان أضيق)</span>
 [% CASE 'parent' %]<span>(المتن الأصلي المباشر)</span>
 [% CASE %][% IF type %]([% type | html %])
 [% END %]
 [% END %]
 </span>
 [% END %]
 [% END %]
[% END %]

[% BLOCK authresult %]
 [% IF ( summary.label ) %][% summary.label | html %]:[% END %]
 [% IF summary.summary %]
 <div class="authority-summary">
 [% summary.summary | html %]
 </div>
 [% END %]
 [% UNLESS ( summary.summaryonly ) %]
 <div class="authorizedheading">
 [% FOREACH authorize IN summary.authorized %]
 <span class="authorizedheading [% IF auth_preview %]authority_preview[% END %]">
 <a data-authid="[% authid | html %]" href="/cgi-bin/koha/authorities/detail.pl?authid=[% authid | uri %]">[% authorize.heading | html %]</a>
 </span>
 [% UNLESS loop.last %] | [% END %]
 [% END %]
 </div>
 [% IF summary.equalterm.size %]
 [% FOREACH term IN summary.equalterm %]
 <div class="equivalentheading">
 <span class="label">=</span>
 <span class="authorizedheading">[% term.heading | html %]</span>
 </div>
 [% END %]
 [% END %]
 [% IF ( marcflavour == 'UNIMARC' ) %]
 [% IF summary.notes %]
 <div class="authres_notes">
 [% FOREACH note IN summary.notes %]
 <span>[% note.note | html %]</span>
 [% END %]
 </div>
 [% END %]
 [% IF summary.seefrom %]
 <div class="authres_seefrom">
 [% FOREACH see IN summary.seefrom %]
 [% PROCESS showreference heading=see.heading linkType="" type=see.type authid=see.authid %]
 [% IF ! loop.last %] ; [% END %]
 [% END %]
 </div>
 [% END %]
 [% IF summary.seealso %]
 <div class="authres_seealso">
 [% FOREACH see IN summary.seealso %]
 [% PROCESS showreference heading=see.heading linkType="" type=see.type authid=see.authid %]
 [% IF ! loop.last %] ; [% END %]
 [% END %]
 </div>
 [% END %]
 [% IF summary.otherscript %]
 <div class="authres_otherscript">
 [% FOREACH other IN summary.otherscript %]
 [% PROCESS language lang=other.lang | trim %]:
 [% other.term | html %]
 [% IF ! loop.last %] ; [% END %]
 [% END %]
 </div>
 [% END %]
 [% ELSE %]
 [% IF summary.notes.size %]
 <div class="authres_notes">
 [% PROCESS notesmodal notes=summary.notes authid=authid %]
 <span><a href="#" data-toggle="modal" data-target="#notesModal_[% authid | html %]">ملاحظات</a></span>
 </div>
 [% END %]
 [% IF ( summary.seefrom.size >= 1 ) %]
 <div class="seefrom">
 <span class="seefrom">يستخدم لـ/انظر من:</span>
 [% FOREACH seefro IN summary.seefrom %]
 <div class="authref">
 [%# Following on one line for translatability %]
 [% PROCESS showreference heading=seefro.heading linkType='seefrom' type=seefro.type authid=seefro.authid %]
 </div>
 [% END %]
 </div>
 [% END %]
 [% IF ( summary.seealso.size >= 1 ) %]
 <div class="seealso">
 <span class="seealso">انظر أيضا:</span>
 [% FOREACH seeals IN summary.seealso %]
 <div class="authref">
 [%# Following on one line for translatability %]
 [% PROCESS showreference heading=seeals.heading linkType='seealso' type=seeals.type authid=seeals.authid %]
 </div>
 [% END %]
 </div>
 [% END %]
 [% END %]
 [% END %]
[% END %]

[% BLOCK language %]
 [% SWITCH lang %]
 [% CASE ['en', 'eng'] %]<span>الإنجليزية</span>
 [% CASE ['fr', 'fre'] %]<span>الفرنسية</span>
 [% CASE ['it', 'ita'] %]<span>الإيطالية</span>
 [% CASE ['de', 'ger', 'deu'] %]<span>الألمانية</span>
 [% CASE ['es', 'spa'] %]<span>الأسبانية</span>
 [% CASE ['heb'] %]<span>العبرية</span>
 [% CASE ['ara'] %]<span>العربية</span>
 [% CASE ['gre'] %]<span>اليونانية (الحديثة)</span>
 [% CASE ['grc'] %]<span>اليونانية (حتى عام 1453)</span>
 [% CASE %]<span>[% lang | html %]</span>
 [% END %]
[% END %]

[% BLOCK notesmodal %]
<!-- notes modal -->
<div style='font-style:normal;' class="modal fade notesModal" id="notesModal_[% authid | html %]" tabindex="-1" role="dialog" aria-labelledby="notesModalLabel">
 <div class="modal-dialog" role="document">
 <div class="modal-content">
 <div class="modal-header">
 <button type="button" class="closebtn" data-dismiss="modal" aria-hidden="true">×</button>
 <h4 class="modal-title" id="notesModalLabel">ملاحظات</h4>
 </div>
 <div class="modal-body">
 <ul>
 [% FOREACH note IN notes %]
 <li>[% note.note | html %]</li>
 [% END %]
 </ul>
 </div>
 <div class="modal-footer">
 <button type="button" class="btn btn-default" data-dismiss="modal">إغلاق</button>
 </div>
 </div>
 </div>
</div>
[% END %]
