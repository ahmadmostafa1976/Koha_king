[% USE Koha %]
[% PROCESS 'form-blocks.inc' %]

<div id="toolbar" class="btn-toolbar">
 <div class="btn-group"><a href="#" id="clear" class="btn btn-default btn-sm"><i class="fa fa-trash-can"></i> مسح الحقل</a></div>
 <div class="btn-group"><a href="#" id="createnew" class="btn btn-default btn-sm"><i class="fa fa-plus"></i> إنشاء استناد جديد</a></div>
</div>
<form name="f" method="get" action="auth_finder.pl">
 <input type="hidden" name="source" value="[% source | html %]" />
 <input type="hidden" name="op" value="do_search" />
 <input type="hidden" name="type" value="intranet" />
 <input type="hidden" name="index" value="[% index | html %]" />
 <fieldset class="rows"><legend>خيارات البحث</legend>
 <ol><li>
 <span class="label">نوع الاستناد: </span>
 [% authtypecode | html %]
 <input type="hidden" name="authtypecode" value="[% authtypecode | html %]" />
 </li>
 <li>
 <label for="mainmainentry">بحث العنوان الرئيسي ($a فقط): </label>
 <input type="hidden" name="marclist" value="mainmainentry" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="mainmainentry">
 [% IF ( operator_mainstr == 'contains' ) %]
 <option value="contains" selected="selected">يحتوى على</option>
 [% ELSE %]
 <option value="contains">يحتوى على</option>
 [% END %]
 [% IF ( operator_mainstr == 'start' ) %]
 <option value="start" selected="selected">يبدأ بـ</option>
 [% ELSE %]
 <option value="start">يبدأ بـ</option>
 [% END %]
 [% IF ( operator_mainstr == 'exact' ) %]
 <option value="exact" selected="selected">بالضبط</option>
 [% ELSE %]
 <option value="exact">بالضبط</option>
 [% END %]
 </select>
 <input id="value_mainstr" style="width:400px;" type="text" name="value_mainstr" value="[% value_mainstr | html %]" />
 <div id="yvaluecontainermainmainentry"></div>
 </li>

 <li>
 <label for="mainentry">بحث الرأس الرئيسي: </label>
 <input type="hidden" name="marclist" value="mainentry" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="mainentry">
 [% IF ( operator_main == 'contains' ) %]
 <option value="contains" selected="selected">يحتوى على</option>
 [% ELSE %]
 <option value="contains">يحتوى على</option>
 [% END %]
 [% IF ( operator_main == 'start' ) %]
 <option value="start" selected="selected">يبدأ بـ</option>
 [% ELSE %]
 <option value="start">يبدأ بـ</option>
 [% END %]
 [% IF ( operator_main == 'exact' ) %]
 <option value="exact" selected="selected">بالضبط</option>
 [% ELSE %]
 <option value="exact">بالضبط</option>
 [% END %]
 </select>
 <input id="value_main" style="width:400px;" type="text" name="value_main" value="[% value_main | html %]" />
 <div id="yvaluecontainermainentry"></div>
 </li>
 <li>
 <label for="marclistheading">بحث كل المقتنيات: </label>
 <input type="hidden" name="marclist" value="match" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="marclistheading">
 [% IF ( operator_match == 'contains' ) %]
 <option value="contains" selected="selected">يحتوى على</option>
 [% ELSE %]
 <option value="contains">يحتوى على</option>
 [% END %]
 [% IF ( operator_match == 'start' ) %]
 <option value="start" selected="selected">يبدأ بـ</option>
 [% ELSE %]
 <option value="start">يبدأ بـ</option>
 [% END %]
 [% IF ( operator_match == 'exact' ) %]
 <option value="exact" selected="selected">بالضبط</option>
 [% ELSE %]
 <option value="exact">بالضبط</option>
 [% END %]
 </select>
 <input id="value_match" style="width:400px;" type="text" name="value_match" value="[% value_match | html %]" />
 <div id="yvaluecontainermarclistheading"></div>
 </li>
 <li>
 <label for="marclistanywhere">بحث التسجيلة بأكملها: </label>
 <input type="hidden" name="marclist" value="all" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="marclistanywhere">
 [% IF ( operator_any == 'contains' ) %]
 <option value="contains" selected="selected">يحتوى على</option>
 [% ELSE %]
 <option value="contains">يحتوى على</option>
 [% END %]
 [% IF ( operator_any == 'start' ) %]
 <option value="start" selected="selected">يبدأ بـ</option>
 [% ELSE %]
 <option value="start">يبدأ بـ</option>
 [% END %]
 [% IF ( operator_any == 'exact' ) %]
 <option value="exact" selected="selected">بالضبط</option>
 [% ELSE %]
 <option value="exact">بالضبط</option>
 [% END %]
 </select>
 <input id="value_any" style="width:400px;" type="text" name="value_any" value="[% value_any | html %]" />
 <div id="yvaluecontainermarclist"></div>
 </li>
 <li>
 <label for="orderby">فرز حسب: </label>
 <select name="orderby" id="orderby">
 [% IF ( orderby == 'HeadingAsc' ) %]
 <option value="HeadingAsc" selected="selected">العنوان أ-ي</option>
 [% ELSE %]
 <option value="HeadingAsc">العنوان أ-ي</option>
 [% END %]
 [% IF ( orderby == 'HeadingDsc' ) %]
 <option value="HeadingDsc" selected="selected">العنوان ي-أ</option>
 [% ELSE %]
 <option value="HeadingDsc">العنوان ي-أ</option>
 [% END %]
 [% IF ( orderby == '' && op ) %]
 <option value="" selected="selected">لا شيء</option>
 [% ELSE %]
 <option value="">لا شيء</option>
 [% END %]
 </select>
 </li></ol></fieldset>
 [% IF source == 'auth' %]
 <fieldset class="rows"><legend>معلومات العلاقة</legend>
 <ol>
 <li>
 <label for="relationship">علاقة خاصة: </label>
 <select name="relationship" id="relationship">
 [% selected=relationship | html %] [% PROCESS selectoptionopen value='' %]غير محدد</option>
 [% IF Koha.Preference('marcflavour') == 'MARC21' %] [% PROCESS selectoptionopen value='a' %]a - رأس سابق</option>
 [% PROCESS selectoptionopen value='b' %]b - رأس لاحق</option>
 [% PROCESS selectoptionopen value='d' %]d - اختصار عبارة</option>
 [% PROCESS selectoptionopen value='f' %]f - قطعة موسيقية</option>
 [% PROCESS selectoptionopen value='g' %]g - مصطلح أشمل</option>
 [% PROCESS selectoptionopen value='h' %]h - مصطلح أضيق</option>
 [% PROCESS selectoptionopen value='i' %]i - عبارة التعليمات المرجعية في الحقل الفرعي $i</option>
 [% PROCESS selectoptionopen value='n' %]n - غير قابل للتطبيق</option>
 [% PROCESS selectoptionopen value='r' %]r - تعيين العلاقة في $i أو $4</option>
 [% PROCESS selectoptionopen value='t' %]t - متن أصلي مباشر</option>
 [% ELSIF Koha.Preference('marcflavour') == 'UNIMARC' %] [% PROCESS selectoptionopen value='a' %]a = اسم سابق</option>
 [% PROCESS selectoptionopen value='b' %]b = اسم لاحق</option>
 [% PROCESS selectoptionopen value='c' %]c = الاسم الرسمي</option>
 [% PROCESS selectoptionopen value='d' %]d = اختصار عبارة / حروف أولى / اختصار</option>
 [% PROCESS selectoptionopen value='e' %]e = اسم مستعار</option>
 [% PROCESS selectoptionopen value='f' %]f = الاسم الحقيقي</option>
 [% PROCESS selectoptionopen value='g' %]g - مصطلح أو اسم أشمل</option>
 [% PROCESS selectoptionopen value='h' %]h - مصطلح أو اسم أضيق</option>
 [% PROCESS selectoptionopen value='i' %]i = اسم في الدين</option>
 [% PROCESS selectoptionopen value='j' %]j = اسم المتزوجة</option>
 [% PROCESS selectoptionopen value='k' %]k = الاسم قبل الزواج</option>
 [% PROCESS selectoptionopen value='l' %]l = اسم مستعار مشترك</option>
 [% PROCESS selectoptionopen value='m' %]m = اسم علماني</option>
 [% PROCESS selectoptionopen value='n' %]n = صيغة قاعدة مختلفة من الاسم</option>
 [% PROCESS selectoptionopen value='o' %]o = الاسم المنسوب / العنوان التقليدي للعمل</option>
 [% PROCESS selectoptionopen value='x' %]x = غير قابل للتطبيق</option>
 [% PROCESS selectoptionopen value='z' %]z = أخرى</option>
 [% END %]
 </select>
 </li>
 </ol>
 </fieldset>
 [% END %]

 <nav class="navbar navbar-default navbar-fixed-bottom">
 <div class="container-fluid">
 <fieldset class="action">
 <input class="btn btn-primary" id="search" type="submit" value="بحث" />
 <input class="btn btn-default" id="clear-form" type="reset" value="مسح النموذج" />
 <button type="button" class="btn btn-default close_window">إغلاق النافذة</button>
 </fieldset>
 </div>
 </nav>
</form>
