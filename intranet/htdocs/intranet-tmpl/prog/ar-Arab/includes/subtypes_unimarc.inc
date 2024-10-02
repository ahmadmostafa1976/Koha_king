<p>
 <a id="show_coded_fields" class="toggle_element" data-element="#Coded_Fields,#show_coded_fields,#hide_coded_fields" href="#"><i class="fa-solid fa-square-plus"></i> إظهار منقحات المعلومات المرمزة</a>
 <a id="hide_coded_fields" class="toggle_element" data-element="#Coded_Fields,#show_coded_fields,#hide_coded_fields" href="#" style="display:none;"><i class="fa-solid fa-square-minus"></i> إخفاء منقحات المعلومات المرمزة</a>
</p>
<div style="display:none;" id="Coded_Fields">
<!-- SUBTYPE LIMITS -->
 <fieldset>
 <legend>الحقول المرمزة</legend>
 <p>
 <label for="audience">الجمهور: </label>
 <select id="audience" name="limit" class="subtype">
 <option value="" selected="selected" >أي</option>
 <option value="ta:a">ناشئة، عام</option>
 <option value="ta:b">ما قبل الابتدائية (0-5)</option>
 <option value="ta:c">الابتدائية (5-8)</option>
 <option value="ta:d">الأطفال (9-14)</option>
 <option value="ta:e">شاب</option>
 <option value="ta:k">بالغ، جدي</option>
 <option value="ta:m">بالغ، عام</option>
 <option value="ta:u">غير معروف</option>
 </select>
 </p>
 <p>
 <label for="physical_presentation">العرض المادي: </label>
 <select id="physical_presentation" name="limit" class="subtype">
 <option value="" selected="selected" >أي</option>
 <option value="ff8-23:r">طبعة منتظمة</option>
 <option value="ff8-23:d">طبعة كبيرة</option>
 <option value="ff8-23:e">تنسيق جريدة</option>
 <option value="ff8-23:f">نص بلغة بريل أو مون</option>
 <option value="ff8-23:g">طبعة مصغرة</option>
 <option value="ff8-23:h">كتابة يدوية</option>
 <option value="ff8-23:i">وسائط متعددة</option>
 <option value="ff8-23:j">طبعة مصغرة</option>
 <option value="ff8-23:s">مورد الكتروني</option>
 <option value="ff8-23:t">ميكروفورم</option>
 <option value="ff8-23:z">شكل آخر من اشكال المواد النصية</option>
 </select>
 </p>
 <p>
 <label for="literary_genre">النوع الأدبي: </label>
 <select id="literary_genre" name="limit" class="subtype">
 <option value="" selected="selected" >أي</option>
 <option value="lf:a">خيال</option>
 <option value="lf:b">دراما</option>
 <option value="lf:c">مقالات</option>
 <option value="lf:d">دعابة ، سخرية</option>
 <option value="lf:e">الرسالة</option>
 <option value="lf:f">قصص قصيرة</option>
 <option value="lf:g">شعر</option>
 <option value="lf:h">خطب، فن الخطابة</option>
 <option value="lf:i">نص كلام الأوبرا</option>
 <option value="lf:y">ليس نص أدبي</option>
 <option value="lf:z">أشكال أدبية متعددة/أخرى</option>
 </select>
 </p>
 <p>
 <label for="biography">السيرة الذاتية: </label>
 <select id="biography" name="limit" class="subtype">
 <option value="">أي</option>
 <option value="bio:y">ليست سيرة ذاتية</option>
 <option value="bio:a">السيرة الذاتية</option>
 <option value="bio:b">سيرة ذاتية فردية</option>
 <option value="bio:c">سيرة جماعية</option>
 <option value="bio:d">يحتوي على بيانات سيرة ذاتية</option>
 </select>
 </p>
 <p>
 <label for="illustration">الإيضاح: </label>
 <select id="illustration" name="limit" class="subtype">
 <option value="">أي</option>
 <option value="ff8-18-21:a">رسومات توضيحية</option>
 <option value="ff8-18-21:b">خرائط</option>
 <option value="ff8-18-21:c">صور</option>
 <option value="ff8-18-21:d">خرائط بيانية</option>
 <option value="ff8-18-21:e">خرائط توضيحية</option>
 <option value="ff8-18-21:f">لوحات</option>
 <option value="ff8-18-21:g">موسيقى</option>
 <option value="ff8-18-21:h">صور طبق الأصل</option>
 <option value="ff8-18-21:i">شعارات</option>
 <option value="ff8-18-21:j">جداول الأنساب</option>
 <option value="ff8-18-21:k">أشكال</option>
 <option value="ff8-18-21:l">عينات</option>
 <option value="ff8-18-21:m">تسجيلات صوتية</option>
 <option value="ff8-18-21:n">شفافيات</option>
 <option value="ff8-18-21:o">زخارف</option>
 <option value="ff8-18-21:y">بدون رسوم توضيحية</option>
 </select>
 </p>
 <p>
 <label for="content">المحتوى: </label>
 <select id="content" name="limit" class="subtype">
 <option value="" >أي</option>
 <option value="ctype:a" >ببليوغرافيا</option>
 <option value="ctype:b" >الفهرس</option>
 <option value="ctype:c" >فهرس</option>
 <option value="ctype:d" >تجريدي</option>
 <option value="ctype:e" >قاموس</option>
 <option value="ctype:f" >موسوعة</option>
 <option value="ctype:g" >دليل</option>
 <option value="ctype:h" >وصف الموضوع</option>
 <option value="ctype:i" >إحصائيات</option>
 <option value="ctype:j" >نصوص كتب مبرمجة</option>
 <option value="ctype:k" >براءات الاختراع</option>
 <option value="ctype:l" >قياسي</option>
 <option value="ctype:m" >رسالة جامعية أو أطروحة</option>
 <option value="ctype:n" >قوانين وتشريعات</option>
 <option value="ctype:o" >جدول عددي</option>
 <option value="ctype:p" >تقرير تقني</option>
 <option value="ctype:q" >ورقة إمتحان</option>
 <option value="ctype:r" >استطلاعات أدبية/مراجعات</option>
 <option value="ctype:s" >اتفاقيات</option>
 <option value="ctype:t" >كارتون أو أشرطة رسوم مصورة</option>
 <option value="ctype:v" >رسالة جامعية أو أطروحة (منقحة)</option>
 <option value="ctype:w" >نص ديني</option>
 <option value="ctype:z" >آخر</option>
 </select>
 </p>
 <p>
 <label for="video_types">أنواع الفيديو: </label>
 <select id="video_types" name="limit" class="subtype">
 <option value="">أي</option>
 <option value="Video-mt:a">صورة متحركة</option>
 <option value="Video-mt:b">اسقاط بصري</option>
 <option value="Video-mt:c">تسجيل فيديو</option>
 </select>
 </p>
 </fieldset>

 <fieldset>
 <legend>الدوريات</legend>
 <p>
 <label for="serial_type">نوع الدورية: </label>
 <select id="serial_type" name="limit" class="subtype">
 <option value="">أي نوع</option>
 <option value="ff8-21:a">دورية</option>
 <option value="ff8-21:b">سلسلة تخصصية</option>
 <option value="ff8-21:c">جريدة</option>
 <option value="ff8-21:e">تحديث ورق سائب</option>
 <option value="ff8-21:f">قاعدة البيانات</option>
 <option value="ff8-21:g">تحديث صفحة الويب</option>
 <option value="ff8-21:z">آخر</option>
 </select>
 </p>
 <p>
 <label for="periodicity">تواتر: </label>
 <select id="periodicity" name="limit" class="subtype">
 <option value="">أي</option>
 <option value="ff8-18:a">يومياً</option>
 <option value="ff8-18:b">نصف اسبوعية</option>
 <option value="ff8-18:c">أسبوعي</option>
 <option value="ff8-18:d">كل أسبوعين</option>
 <option value="ff8-18:e">نصف شهرية</option>
 <option value="ff8-18:f">شهري</option>
 <option value="ff8-18:g">نصف شهري</option>
 <option value="ff8-18:h">فصلي</option>
 <option value="ff8-18:i">ثلاث مرات في السنة</option>
 <option value="ff8-18:j">نصف سنوية</option>
 <option value="ff8-18:k">سنوي</option>
 <option value="ff8-18:l">كل سنتين</option>
 <option value="ff8-18:m">كل ثلاث سنوات</option>
 <option value="ff8-18:n">ثلاث مرات في الإسبوع</option>
 <option value="ff8-18:o">ثلاث مرات في الشهر</option>
 <option value="ff8-18:y">بدون تواتر</option>
 <option value="ff8-18:u">غير معروف</option>
 <option value="ff8-18:z">آخر</option>
 </select>
 </p>
 <p>
 <label for="regularity">الانتظام: </label>
 <select id="regularity" name="limit" class="subtype">
 <option value="">أي انتظام</option>
 <option value="ff8-19:a">منتظم</option>
 <option value="ff8-19:b">عد انتظام تم تطبيعه</option>
 <option value="ff8-19:y">غير منظم</option>
 <option value="ff8-19:u">غير معروف</option>
 </select>
 </p>
 </fieldset>

 <fieldset>
 <legend>صورة</legend>
 <p>
 <select name="limit" class="subtype">
 <option value="">أي</option>
 <option value="Graphics-type:a">فن تلصيقي</option>
 <option value="Graphics-type:b">رسم</option>
 <option value="Graphics-type:c">لوحة</option>
 <option value="Graphics-type:d">الاستنساخ الضوئي</option>
 <option value="Graphics-type:e">الصورة السلبية</option>
 <option value="Graphics-type:f">طباعة الصور</option>
 <option value="Graphics-type:h">صور</option>
 <option value="Graphics-type:i">طباعة</option>
 <option value="Graphics-type:k">رسم تقني</option>
 <option value="Graphics-type:z">نوع رسم غير معروض آخر</option>
 </select>
 <select name="limit" class="subtype">
 <option value="">أي</option>
 <option value="Graphics-support:a">كانفاه</option>
 <option value="Graphics-support:b">لوحة بريستول</option>
 <option value="Graphics-support:c">لوح كرتون/لوح شرح</option>
 <option value="Graphics-support:d">زجاج</option>
 <option value="Graphics-support:j">جص</option>
 <option value="Graphics-support:k">ألواح</option>
 <option value="Graphics-support:l">بورسلين</option>
 <option value="Graphics-support:m">حجر</option>
 <option value="Graphics-support:n">خشب</option>
 <option value="Graphics-support:v">مجموعة مختلطة</option>
 <option value="Graphics-support:e">مواد تركيبية</option>
 <option value="Graphics-support:f">جلد</option>
 <option value="Graphics-support:g">نسيج</option>
 <option value="Graphics-support:h">معدن</option>
 <option value="Graphics-support:i">ورقة</option>
 <option value="Graphics-support:z">آخرون</option>
 <option value="Graphics-support:u">غير معروف</option>
 </select>
 </p>
</fieldset>
</div>
