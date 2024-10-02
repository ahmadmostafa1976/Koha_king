<option value="relevance">الصلة</option>

<optgroup label="الشعبية">
 
 [% IF ( sort_by == "popularity_dsc" ) %]
<option value="popularity_dsc" selected="selected">شعبية (أكثر إلى أقلّ)</option>
[% ELSE %]
 <option value="popularity_dsc">شعبية (أكثر إلى أقلّ)</option>
 [% END %]
[% IF ( sort_by == "popularity_asc" ) %]
<option value="popularity_asc" selected="selected">شعبية (أقلّ إلى أكثر)</option>
[% ELSE %]
 <option value="popularity_asc">شعبية (أقلّ إلى أكثر)</option>
 [% END %]

</optgroup>

<optgroup label="مؤلف">
 
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
<option value="call_number_asc" selected="selected">رقم الطلب (Z-A to 9-0)</option>
[% ELSE %]
 <option value="call_number_asc">رقم الطلب (Z-A to 9-0)</option>
[% END %]

[% IF ( sort_by == "call_number_dsc" ) %]
<option value="call_number_dsc" selected="selected">رقم الطلب (Z-A to 9-0)</option>
[% ELSE %]
 <option value="call_number_dsc">رقم الطلب (Z-A to 9-0)</option>
[% END %]

</optgroup>

<optgroup label="تواريخ">
 [% IF ( sort_by == "pubdate_dsc" ) %]
<option value="pubdate_dsc" selected="selected" >تاريخ حقوق النشر/النشر: من الأحدث إلى الأقدم</option>
 [% ELSE %]
<option value="pubdate_dsc">تاريخ حقوق النشر/النشر: من الأحدث إلى الأقدم</option>
[% END %]

[% IF ( sort_by == "pubdate_asc" ) %]
<option value="pubdate_asc" selected="selected" >تاريخ حقوق النشر/النشر: من الأقدم إلى الأحدث</option>
[% ELSE %]
<option value="pubdate_asc">تاريخ حقوق النشر/النشر: من الأقدم إلى الأحدث</option>
[% END %]

[% IF ( sort_by == "acqdate_dsc" ) %]
<option value="acqdate_dsc" selected="selected">تاريخ التزويد: من الأقدم لأحدث</option>
[% ELSE %]
<option value="acqdate_dsc">تاريخ التزويد: من الأقدم لأحدث</option>
 [% END %]

 [% IF ( sort_by == "acqdate_asc" ) %]
<option value="acqdate_asc" selected="selected">تاريخ التزويد: الأقدم للأحدث</option>
[% ELSE %]
<option value="acqdate_asc">تاريخ التزويد: الأقدم للأحدث</option>
 [% END %]
</optgroup>

<optgroup label="عنوان">
 [% IF ( sort_by == "title_az" || sort_by == "title_asc" ) %]
<option value="title_az" selected="selected">عنوان (A-Z)</option>
 [% ELSE %]
<option value="title_az">عنوان (A-Z)</option>
 [% END %]
 [% IF ( sort_by == "title_za" || sort_by == "title_dsc" ) %]
<option value="title_za" selected="selected">عنوان (Z-A)</option> 
 [% ELSE %]
<option value="title_za">عنوان (Z-A)</option>
[% END %]
</optgroup>
