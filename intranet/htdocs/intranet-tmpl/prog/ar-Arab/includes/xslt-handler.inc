[% SWITCH code %]
 [% CASE 'XSLTH_ERR_NO_FILE' %]
 <span>لم يتم تمرير ملف XSLT.</span>
 [% CASE 'XSLTH_ERR_FILE_NOT_FOUND' %]
 <span>لم يتم العثور على ملف XSLT.</span>
 [% CASE 'XSLTH_ERR_LOADING' %]
 <span>خطأ أثناء تحميل ورقة الأنماط.</span>
 [% CASE 'XSLTH_ERR_PARSING_CODE' %]
 <span>خطأ أثناء تحليل ورقة الأنماط.</span>
 [% CASE 'XSLTH_ERR_PARSING_DATA' %]
 <span>خطأ أثناء تحليل الإدخال.</span>
 [% CASE 'XSLTH_ERR_TRANSFORMING' %]
 <span>خطأ أثناء تحويل الإدخال.</span>
 [% CASE 'XSLTH_NO_STRING_PASSED' %]
 <span>لا يوجد مقطع للتحويل.</span>
[% END %]
