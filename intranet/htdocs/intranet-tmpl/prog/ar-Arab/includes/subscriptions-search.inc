[% PROCESS 'html_helpers.inc' %]
<div id="advsearch">
 <form action="" method="get">
 <fieldset class="brief">
 <a href="#" class="toggle_element" data-element="#advsearch_form">بحث متقدم</a>
 <div id="advsearch_form" style="display:none">
 <ol>
 <li>
 <label for="issn">تدمد:</label>
 <input type="text" id="issn" name="ISSN_filter" value="[% ISSN_filter | html %]" />
 </li>
 <li>
 <label for="title">العنوان:</label>
 <input type="text" id="title" name="title_filter" value="[% title_filter | html %]" />
 </li>
 [% IF Koha.Preference( 'marcflavour' ) == "UNIMARC" %]
 <li>
 <label for="ean">EAN:</label>
 <input type="text" id="ean" name="EAN_filter" value="[% EAN_filter | html %]" />
 </li>
 [% END %]
 <li>
 <label for="publisher">الناشر:</label>
 <input type="text" id="publisher" name="publisher_filter" value="[% publisher_filter | html %]" />
 </li>
 <li>
 <label for="supplier">المزود:</label>
 <input type="text" id="supplier" name="supplier_filter" value="[% supplier_filter | html %]" />
 </li>
 <li>
 <label for="branch">المكتبة:</label>
 <select id="branch" name="branch_filter">
 <option value="">الكل</option>
 [%# FIXME Should not we filter the libraries? %]
 [% PROCESS options_for_libraries libraries => Branches.all( selected => branch_filter, unfiltered => 1 ) %]
 </select>
 </li>
 </ol>
 <input type="hidden" name="searched" value="1" />
 [% IF (booksellerid) %]
 <input type="hidden" name="booksellerid" value="[% booksellerid | html %]" />
 [% END %]
 [% IF (basketno) %]
 <input type="hidden" name="basketno" value="[% basketno | html %]" />
 [% END %]
 </div>
 </fieldset>
 <fieldset class="action">
 <input class="btn btn-primary" type="submit" value="بحث" />
 </fieldset>
 </form>
</div>
