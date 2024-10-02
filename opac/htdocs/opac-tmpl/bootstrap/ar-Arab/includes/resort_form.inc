<option value="relevance">الصلة</option>
<optgroup label="الشعبية">
 [% IF ( sort_by == "popularity_dsc" ) %]
 <option value="popularity_dsc" selected="selected">الشعبية (أكثر إلى أقلّ)</option>
 [% ELSE %]
 <option value="popularity_dsc">الشعبية (أكثر إلى أقلّ)</option>
 [% END %]
 [% IF ( sort_by == "popularity_asc" ) %]
 <option value="popularity_asc" selected="selected">الشعبية (أقلّ إلى أكثر)</option>
 [% ELSE %]
 <option value="popularity_asc">الشعبية (أقلّ إلى أكثر)</option>
 [% END %]
</optgroup>
<optgroup label="المؤلف">
 [% IF ( sort_by == "author_az" || sort_by == "author_asc" ) %]
 <option value="author_az" selected="selected">المؤلف (تصاعدياً)</option>
 [% ELSE %]
 <option value="author_az">المؤلف (تصاعدياً)</option>
 [% END %]
 [% IF ( sort_by == "author_za" || sort_by == "author_dsc" ) %]
 <option value="author_za" selected="selected">المؤلف (تنازلياً)</option>
 [% ELSE %]
 <option value="author_za">المؤلف (تنازلياً)</option>
 [% END %]
</optgroup>
<optgroup label="رقم الاستدعاء">
 [% IF ( sort_by == "call_number_asc" ) %]
 <option value="call_number_asc" selected="selected">رقم الاستدعاء(Z-A إلى 9-0)</option>
 [% ELSE %]
 <option value="call_number_asc">رقم الاستدعاء(Z-A إلى 9-0)</option>
 [% END %]
 [% IF ( sort_by == "call_number_dsc" ) %]
 <option value="call_number_dsc" selected="selected">رقم الاستدعاء (Z-A إلى 9-0)</option>
 [% ELSE %]
 <option value="call_number_dsc">رقم الاستدعاء (Z-A إلى 9-0)</option>
 [% END %]
</optgroup>
<optgroup label="تواريخ">
 [% IF ( sort_by == "pubdate_dsc" ) %]
 <option value="pubdate_dsc" selected="selected">تاريخ النشر/حقوق الطبع والنشر:الأحدث الى الأقدم</option>
 [% ELSE %]
 <option value="pubdate_dsc">تاريخ النشر/حقوق الطبع والنشر:الأحدث الى الأقدم</option>
 [% END %]
 [% IF ( sort_by == "pubdate_asc" ) %]
 <option value="pubdate_asc" selected="selected">تاريخ النشر / حقوق الطبع والنشر  : الأقدم إلى الأحدث</option>
 [% ELSE %]
 <option value="pubdate_asc">تاريخ النشر / حقوق الطبع والنشر  : الأقدم إلى الأحدث</option>
 [% END %]
 [% IF ( sort_by == "acqdate_dsc" ) %]
 <option value="acqdate_dsc" selected="selected">تاريخ التزويد: من الأحدث الى الأقدم</option>
 [% ELSE %]
 <option value="acqdate_dsc">تاريخ التزويد: من الأحدث الى الأقدم</option>
 [% END %]
 [% IF ( sort_by == "acqdate_asc" ) %]
 <option value="acqdate_asc" selected="selected">تاريخ التزويد: من الأقدم الى الأحدث</option>
 [% ELSE %]
 <option value="acqdate_asc">تاريخ التزويد: من الأقدم الى الأحدث</option>
 [% END %]
</optgroup>
<optgroup label="عنوان">
 [% IF ( sort_by == "title_az" || sort_by == "title_asc" ) %]
 <option value="title_az" selected="selected">عنوان (تصاعدي)</option>
 [% ELSE %]
 <option value="title_az">عنوان (تصاعدي)</option>
 [% END %]
 [% IF ( sort_by == "title_za" || sort_by == "title_dsc" ) %]
 <option value="title_za" selected="selected">عنوان (تنازلي)</option>
 [% ELSE %]
 <option value="title_za">عنوان (تنازلي)</option>
 [% END %]
</optgroup>
