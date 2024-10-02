[% SWITCH error %]
[% CASE 'no_item' %]
 <span>لم يتم العثور على مادة متطابقة</span>
[% CASE 'no_checkout' %]
 <span>المادة غير معارة</span>
[% CASE 'too_soon' %]
 <span>لا يمكن تجديده بعد</span>
[% CASE 'too_many' %]
 <span>تم تجديدها إلى الحد الأقصى من عدد المرات بواسطة</span>
[% CASE 'auto_too_soon' %]
 <span>مجدول للتجديد التلقائي ولا يمكن تجديده بعد</span>
[% CASE 'auto_too_late' %]
 <span>مجدول للتجديد التلقائي ولا يمكن تجديده بعد الآن</span>
[% CASE 'auto_account_expired' %]
 <span>مجدول للتجديد التلقائي ولا يمكن تجديده بسبب انتهاء حساب المستفيد</span>
[% CASE 'auto_renew' %]
 <span>مجدول للتجديد التلقائي</span>
[% CASE 'auto_too_much_oweing' %]
 <span>مجدول للتجديد التلقائي ولا يمكن تجديده لأن المستفيد لديه الكثير من الرسوم غير المدفوعة</span>
[% CASE 'on_reserve' %]
 <span>في الحجز لمستفيد آخر</span>
[% CASE 'patron_restricted' %]
 <span>المستفيد مقيد حالياً</span>
[% CASE 'item_denied_renewal' %]
 <span>غير مسموح بتجديد المادة</span>
[% CASE 'onsite_checkout' %]
 <span>المادة للإعارة في الموقع</span>
[% CASE 'has_fine' %]
 <span>المادة عليها غرامة قائمة</span>
[% CASE 'item_issued_to_other_patron'%]
 <span>تم إصدار المادة بالفعل لمستعير آخر</span>
[% CASE %]
 <span>خطأ غير معروف</span>
[% END %]
