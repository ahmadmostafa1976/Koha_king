[% USE Koha %]
[% IF refiner %]
 <select class="advsearch" name="idx" id="refiner_idx">
[% ELSE %]
 <select class="advsearch" name="idx" id="idx">
[% END %]
 [% IF ms_kw %]
 <option selected="selected" value="kw">الكلمة المفتاحية</option>
 [% ELSE %]
 <option value="kw">الكلمة المفتاحية</option>
 [% END %]
 [% IF ms_kwcommaphr %]
 <option selected="selected" value="kw,phr">&nbsp;&nbsp;&nbsp;&nbsp; الكلمة المفتاحية كجملة</option>
 [% ELSE %]
 <option value="kw,phr">&nbsp;&nbsp;&nbsp;&nbsp; الكلمة المفتاحية كجملة</option>
 [% END %]
 [% IF ms_au %]
 <option selected="selected" value="au">مؤلف</option>
 [% ELSE %]
 <option value="au">مؤلف</option>
 [% END %]
 [% IF ms_aucommaphr %]
 <option selected="selected" value="au,phr">&nbsp;&nbsp;&nbsp;&nbsp; المؤلف كعبارة</option>
 [% ELSE %]
 <option value="au,phr">&nbsp;&nbsp;&nbsp;&nbsp; المؤلف كعبارة</option>
 [% END %]
 [% IF ms_cpn %]
 <option selected="selected" value="cpn">&nbsp;&nbsp;&nbsp;&nbsp; الاسم المؤسسي</option>
 [% ELSE %]
 <option value="cpn">&nbsp;&nbsp;&nbsp;&nbsp; الاسم المؤسسي</option>
 [% END %]
 [% IF ms_cfn %]
 <option selected="selected" value="cfn">&nbsp;&nbsp;&nbsp;&nbsp; اسم المؤتمر</option>
 [% ELSE %]
 <option value="cfn">&nbsp;&nbsp;&nbsp;&nbsp; اسم المؤتمر</option>
 [% END %]
 [% IF ms_cpncommaphr %]
 <option selected="selected" value="cpn,phr">&nbsp;&nbsp;&nbsp;&nbsp;  الاسم المؤسسي كعبارة</option>
 [% ELSE %]
 <option value="cpn,phr">&nbsp;&nbsp;&nbsp;&nbsp;  الاسم المؤسسي كعبارة</option>
 [% END %]
 [% IF ms_cfncommaphr %]
 <option selected="selected" value="cfn,phr">&nbsp;&nbsp;&nbsp;&nbsp; اسم المؤتمر كعبارة</option>
 [% ELSE %]
 <option value="cfn,phr">&nbsp;&nbsp;&nbsp;&nbsp; اسم المؤتمر كعبارة</option>
 [% END %]
 [% IF ms_pn %]
 <option selected="selected" value="pn">&nbsp;&nbsp;&nbsp;&nbsp; اسم شخصى</option>
 [% ELSE %]
 <option value="pn">&nbsp;&nbsp;&nbsp;&nbsp; اسم شخصى</option>
 [% END %]
 [% IF ms_pncommaphr %]
 <option selected="selected" value="pn,phr">&nbsp;&nbsp;&nbsp;&nbsp; الاسم الشخصي كعبارة</option>
 [% ELSE %]
 <option value="pn,phr">&nbsp;&nbsp;&nbsp;&nbsp; الاسم الشخصي كعبارة</option>
 [% END %]
 [% IF ms_ti %]
 <option selected="selected" value="ti">عنوان</option>
 [% ELSE %]
 <option value="ti">عنوان</option>
 [% END %]
 [% IF ms_ticommaphr %]
 <option selected="selected" value="ti,phr">&nbsp;&nbsp;&nbsp;&nbsp; العنوان كعبارة</option>
 [% ELSE %]
 <option value="ti,phr">&nbsp;&nbsp;&nbsp;&nbsp; العنوان كعبارة</option>
 [% END %]
 [% IF ms_se %]
 <option selected="seleced" value="se">&nbsp;&nbsp;&nbsp;&nbsp; عنوان السلسلة</option>
 [% ELSE %]
 <option value="se">&nbsp;&nbsp;&nbsp;&nbsp; عنوان السلسلة</option>
 [% END %]
 [% IF ms_su %]
 <option selected="selected" value="su">الموضوع</option>
 [% ELSE %]
 <option value="su">الموضوع</option>
 [% END %]
 [% IF ms_sucommaphr %]
 <option selected="selected" value="su,phr">&nbsp;&nbsp;&nbsp;&nbsp; الموضوع كعبارة</option>
 [% ELSE %]
 <option value="su,phr">&nbsp;&nbsp;&nbsp;&nbsp; الموضوع كعبارة</option>
 [% END %]
 [% IF ( expanded_options ) %]
 [% IF ms_sudashbr %]
 <option selected="selected" value="su-br">&nbsp;&nbsp;&nbsp;&nbsp; موضوع ومصطلحات أشمل</option>
 [% ELSE %]
 <option value="su-br">&nbsp;&nbsp;&nbsp;&nbsp; موضوع ومصطلحات أشمل</option>
 [% END %]
 [% IF ms_sudashna %]
 <option selected="selected" value="su-na">&nbsp;&nbsp;&nbsp;&nbsp; موضوع ومصطلحات أضيق</option>
 [% ELSE %]
 <option value="su-na">&nbsp;&nbsp;&nbsp;&nbsp; موضوع ومصطلحات أضيق</option>
 [% END %]
 [% IF ms_sudashrl %]
 <option selected="selected" value="su-rl">&nbsp;&nbsp;&nbsp;&nbsp; موضوع ومصطلحات ذات صلة</option>
 [% ELSE %]
 <option value="su-rl">&nbsp;&nbsp;&nbsp;&nbsp; موضوع ومصطلحات ذات صلة</option>
 [% END %]
 [% END %]
 [% IF ms_bc %]
 <option selected="selected" value="bc">الباركود</option>
 [% ELSE %]
 <option value="bc">الباركود</option>
 [% END %]
 [% IF ms_locationcommawrdl %]
 <option selected="selected" title="إدخال قيمة رمز الموقع للبحث" value="location,wrdl">موقع الترفيف (رمز)</option>
 [% ELSE %]
 <option title="إدخال قيمة رمز الموقع للبحث" value="location,wrdl">موقع الترفيف (رمز)</option>
 [% END %]
 [% IF ( Koha.Preference('IntranetNumbersPreferPhrase') ) %]
 [% IF ms_identcommaphr %]
 <option selected="selected" value="ident,phr">الرقم المعياري</option>
 [% ELSE %]
 <option value="ident,phr">الرقم المعياري</option>
 [% END %]
 [% ELSE %]
 [% IF ms_ident %]
 <option selected="selected" value="ident">الرقم المعياري</option>
 [% ELSE %]
 <option value="ident">الرقم المعياري</option>
 [% END %]
 [% END %]
 [% IF ms_nb %]
 <option selected="selected" value="nb">&nbsp;&nbsp;&nbsp;&nbsp; تدمك</option>
 [% ELSE %]
 <option value="nb">&nbsp;&nbsp;&nbsp;&nbsp; تدمك</option>
 [% END %]
 [% IF ms_ns %]
 <option selected="selected" value="ns">&nbsp;&nbsp;&nbsp;&nbsp; تدمد</option>
 [% ELSE %]
 <option value="ns">&nbsp;&nbsp;&nbsp;&nbsp; تدمد</option>
 [% END %]
 [% IF ( Koha.Preference('IntranetNumbersPreferPhrase') ) %]
 [% IF ms_callnumcommaphr %]
 <option selected="selected" value="callnum,phr">&nbsp;&nbsp;&nbsp;&nbsp; رقم الإستدعاء</option>
 [% ELSE %]
 <option value="callnum,phr">&nbsp;&nbsp;&nbsp;&nbsp; رقم الإستدعاء</option>
 [% END %]
 [% ELSE %]
 [% IF ms_callnum %]
 <option selected="selected" value="callnum">&nbsp;&nbsp;&nbsp;&nbsp; رقم الإستدعاء</option>
 [% ELSE %]
 <option value="callnum">&nbsp;&nbsp;&nbsp;&nbsp; رقم الإستدعاء</option>
 [% END %]
 [% END %]
 [% IF ms_lncommartrn %]
 <option selected="selected" value="ln,rtrn">اللغة</option>
 [% ELSE %]
 <option value="ln,rtrn">اللغة</option>
 [% END %]
 [% IF ms_nt %]
 <option selected="selected" value="nt">ملاحظات/تعليقات</option>
 [% ELSE %]
 <option value="nt">ملاحظات/تعليقات</option>
 [% END %]
 [% IF (marcflavour != 'UNIMARC' ) %]
 [% IF ms_curriculum %]
 <option selected="selected" value="curriculum">المناهج الدراسية</option>
 [% ELSE %]
 <option value="curriculum">المناهج الدراسية</option>
 [% END %]
 [% END %]
 [% IF ms_pb %]
 <option selected="selected" value="pb">الناشر</option>
 [% ELSE %]
 <option value="pb">الناشر</option>
 [% END %]
 [% IF ms_pl %]
 <option selected="selected" value="pl">موقع الناشر</option>
 [% ELSE %]
 <option value="pl">موقع الناشر</option>
 [% END %]

 [%# Use non-normalized st-year instead of st-numeric, %]
 [%# since pubdate can include 'u' to signify unknown %]
 [%# dates. See "Legal Characters" at: %]
 [%# http://www.loc.gov/marc/bibliographic/bd008a.html %]
 [%# This search is also for date ranges due to the %]
 [%# special Zebra r=r CCL mapping for 'yr' %]
 [% IF ms_yrcommastdashyear %]
 <option selected="selected" value="yr,st-year">تاريخ النشر (السنة- السنة)</option>
 [% ELSE %]
 <option value="yr,st-year">تاريخ النشر (السنة- السنة)</option>
 [% END %]
 [% IF ms_acqdatecommastdashdatedashnormalized %]
 <option selected="selected" value="acqdate,st-date-normalized">تاريخ التزويد (yyyy-mm-dd)</option>
 [% ELSE %]
 <option value="acqdate,st-date-normalized">تاريخ التزويد (yyyy-mm-dd)</option>
 [% END %]
</select>
