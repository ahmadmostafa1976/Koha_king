[% BLOCK showhierarchy %]
 [% FOREACH tree IN trees %]
 [% PROCESS showtree tree = tree marc = marc %]
 [% END %]
[% END %]

[% BLOCK showtree %]
 <ul class="hierarchy">
 [% FOREACH node IN tree %]
 <li id="hier[% node.authid | html %]" class="[% node.class | html %] authnode">
 [% IF ( node.current_value ) %]
 <span class="currentauth">[% node.value | html %]</span>
 [% ELSE %]
 <a href="opac-authoritiesdetail.pl?authid=[% node.authid | uri %]&marc=[% marc | uri %]" title="مصطلح">[% node.value | html %]</a>
 [% END %]
 [% IF ( node.children && node.children.size > 0 ) %]
 [% PROCESS showtree tree = node.children marc = marc %]
 [% END %]
 </li>
 [% END %]
 </ul>
[% END %]

[% BLOCK authtypelabel %]
 [% UNLESS ( type=='seefrom' || type=='seealso' || type=='' ) %]
 <span class="type">[% FILTER trim %][% SWITCH type %]
 [% CASE 'earlier' %]<span>رأس سابق</span>
 [% CASE 'later' %]<span>رأس لاحق</span>
 [% CASE 'acronym' %]<span>الحروف الأولى من الكلمات</span>
 [% CASE 'musical' %]<span>قطعة موسيقية</span>
 [% CASE 'broader' %]<span>عنوان أشمل</span>
 [% CASE 'narrower' %]<span>عنوان أضيق</span>
 [% CASE %]<span>[% type | html %]</span>
 [% END %][% END %]</span>
 [% END %]
[% END %]

[% BLOCK otherscript %]
 [% FOREACH heading IN headings %]
 [% IF heading.category == wantcategory %]
 [% IF heading.direction == 'ltr' %]
 <div class="heading otherscript [% heading.category | html %]">
 <span class="[% heading.category | html %]">[% heading.term | html %]</span>
 </div>
 [% ELSIF heading.direction == 'rtl' %]
 <div class="heading otherscript [% heading.category | html %] rtl">
 <span class="[% heading.category | html %]">[% heading.term | html %]</span>
 </div>
 [% END %]
 [% END %]
 [% END %]
[% END %]

[% BLOCK authheadingdisplay %]
 [% IF authid %]<a href="/cgi-bin/koha/opac-authoritiesdetail.pl?authid=[% authid | uri %]">[% heading | html %]</a>
 [% ELSIF search %]<a href="/cgi-bin/koha/opac-authorities-home.pl?op=do_search&amp;type=opac&amp;operator=contains&amp;marclist=mainentry&amp;and_or=and&amp;orderby=HeadingAsc&amp;value=[% search | uri %]">[% heading | html %]</a>
 [% ELSE %][% heading | html %]
 [% END %]
[% END %]

[% BLOCK language %]
 [% SWITCH lang %]
 [% CASE ['en', 'eng'] %]<span>الإنجليزية</span>
 [% CASE ['fr', 'fre'] %]<span>الفرنسية</span>
 [% CASE ['it', 'ita'] %]<span>الإيطالية</span>
 [% CASE ['de', 'ger', 'deu'] %]<span>الألمانية</span>
 [% CASE ['es', 'spa'] %]<span>الأسبانية</span>
 [% CASE %]<span>[% lang | html %]</span>
 [% END %]
[% END %]
