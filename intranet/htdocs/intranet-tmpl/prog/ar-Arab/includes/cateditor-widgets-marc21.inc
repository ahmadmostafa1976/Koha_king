<div id="editor-widget-templates" style="display:none">
 <div id="widget-leader">
 الفاتح:&nbsp;<span title="طول التسجيلة (تلقائي التوليد)">#####</span>
 <select name="f5" title="حالة التسجيلة">
 <option value="a">a-زيادة في مستوى الترميز</option>
 <option value="c">c- مصحح أو مراجع</option>
 <option value="d">d-محذوف</option>
 <option value="n">n - جديد</option>
 <option value="p">p-زيادة في مستوى الترميز من قبل النشر</option>
 </select>
 <select name="f6" title="نوع التسجيلة. يتحكم في النوع الافتراضي لحقل 008.">
 <option value="a">a-مادة لغة</option>
 <option value="c">c- موسيقى منوتة</option>
 <option value="d">d- نوتة موسيقية مخطوطة</option>
 <option value="e">e- مادة خرائطية</option>
 <option value="f">f - مادة خرائطية مخطوطة</option>
 <option value="g">g - وسيط عرض</option>
 <option value="i">i - تسجيل صوتي غير موسيقي</option>
 <option value="j">j - تسجيل صوت موسيقي</option>
 <option value="k">k - رسم ثنائي الابعاد غير قابل للعرض</option>
 <option value="m">m - ملف الحاسب</option>
 <option value="o">o - عدة</option>
 <option value="p">p - مواد متنوعة</option>
 <option value="r">r - قطعة أثرية ثلاثية الأبعاد أو كائن طبيعي التكوين</option>
 <option value="t">t - مادة لغة مخطوطة</option>
 </select>
 <select name="f7" title="المستوى الببليوغرافي">
 <option value="a">a- جزء مكون لدراسة أحادية</option>
 <option value="b">b-جزء مكوّن لدورية</option>
 <option value="c">c- مجموعة</option>
 <option value="d">d- وحدة فرعية</option>
 <option value="i">i - مورد متكامل</option>
 <option value="m">m- دراسة أحادية/ مادة</option>
 <option value="s">s- دورية</option>
 </select>
 <select name="f8" title="نوع التحكم">
 <option value=" ">_ - نوع غير محدد</option>
 <option value="a">a- أرشيفي</option>
 </select>
 <span title="ترميز (يونيكود قسري)">a</span>
 <span title="أطوال المؤشر/ الحقل الفرعي">22</span>
 <span title="عنوان قاعدة البيانات (تلقائي التوليد)">#####</span>
 <select name="f17" title="مستوى الترميز">
 <option value=" ">_ - المستوى الكامل</option>
 <option value="1">1- المستوى الكامل، المادة غير مفحوصة</option>
 <option value="2">2 -أقل-من-المستوى الكامل, مادة غير مفحوصة</option>
 <option value="3">3- المستوى المختصر</option>
 <option value="4">4-المستوى الرئيسى</option>
 <option value="5">5-المستوى الجزئى (التمهيدى)</option>
 <option value="7">7- المستوى الأدنى</option>
 <option value="8">8- مستوى ما قبل النشر</option>
 [% IF Koha.Preference('UseOCLCEncodingLevels') %]
 <option value="I">I- مدخلات كاملة المستوى من قبل المشاركين في مركز المكتبة الرقمية على الإنترنت</option>
 <option value="J">‫J- تسجيلة محذوفة</option>
 <option value="K">K- مدخلات أقل من كاملة من قبل المشاركين في مركز المكتبة الرقمية على الإنترنت</option>
 <option value="M">M- مضاف من عملية بالدفعة</option>
 [% END %]
 <option value="u">u - غير معروف</option>
 <option value="z">z- غير قابل للتطبيق</option>
 </select>
 <select name="f18" title="نموذج الفهرسة الوصفية">
 <option value=" ">_ - بدون-تدمك</option>
 <option value="a">a - AACR 2</option>
 <option value="c">c- ISBD حذف ترقيم</option>
 <option value="i">i- تدمك شامل الترقيم</option>
 <option value="n">n - تم حذف ترقيم ليس ترقيم ISBD</option>
 <option value="u">u - غير معروف</option>
 </select>
 <select name="f19" title="مستوى التسجيلة ذات المصدر متعدد الأجزاء">
 <option value=" ">_ - غير محدد أو غير قابل للتطبيق</option>
 <option value="a">a-ضبط</option>
 <option value="b">b- جزء بعنوان مستقل</option>
 <option value="c">c- جزء مع عنوان تابع</option>
 </select>
 <span title="طول عناصر المسار">4500</span>
 </div>
</div>
<!-- cateditor-widgets-marc21.inc -->
<script>

/**
 * Each widget should provide one to three methods:
 *   init( text ): Returns the DOM node for this widget.
 *   postCreate( node, mark ): Optional, called once the mark has been created
 *                             and the node shown. Bind event handlers here.
 *   makeTemplate(): Optional, should return some sane default contents for a
 *                   newly created field/subfield. '<empty>' will be used if this
 *                   method is unset.
 *
 * Following the Koha convention, control fields are defined as tags with a
 * single subfield, '@'.
 */

require( [ 'koha-backend', 'widget', 'text-marc' ], function( KohaBackend, Widget, TextMarc ) {
    Widget.Register( '000@', {
        makeTemplate: function() {
            return '     nam a22     7a 4500';
        },
        init: function() {
            var $result = $( '<span class="subfield-widget fixed-widget"></span>' );

            return $result[0];
        },
        postCreate: function() {
            // Clear the length and directory start fields; these are unnecessary for MARCXML and will be filled in upon USMARC export
            this.setFixed( 0, 5, '     ' );
            this.setFixed( 9, 17, 'a22     ' );
            this.setFixed( 20, 24, '4500' );

            this.insertTemplate( '#widget-leader' );

            this.bindFixed( '[name=f5]', 5, 6 );
            this.bindFixed( '[name=f6]', 6, 7 );
            this.bindFixed( '[name=f7]', 7, 8 );
            this.bindFixed( '[name=f8]', 8, 9 );
            this.bindFixed( '[name=f17]', 17, 18 );
            this.bindFixed( '[name=f18]', 18, 19 );
            this.bindFixed( '[name=f19]', 19, 20 );
        },
    } );

    /* Check to see if there are any Control Number entries
     *  in the authorised values table.
     * If not, let's not show the widget
     */
    var reg001 = KohaBackend.GetAuthorisedValues( 'CONTROL_NUM_SEQUENCE');
    if(reg001) {

        Widget.Register( '001@', {
            init: function() {
                var $result = $(
                    '<span class="subfield-widget">'
                    + _("رقم التحكم: ")
                    + '<span class="control-number-widget-contents"></span>'
                    + '<button class="control-number-widget-assign">' + _("تعيين التالي") + '</button>'
                    + '<select class="control-number-widget-sequence"></select>'
                    + '<button class="control-number-widget-override">' + _("تخطي") + '</button>'
                    + '</span>'
                );

                return $result[0];
            },
            setControlNumber: function( text ) {
                if ( text ) this.setText( text );
                $( this.node ).find('.control-number-widget-contents')
                    .html( text == '<empty>' ? ( '<span class="hint">' + _("إلغاء ضبط") + '</span>' ) : text );
                this.mark.changed();
            },
            postCreate: function( node, mark ) {
                var widget = this;
                this.setControlNumber( this.text );
                $( this.node )
                    .find('.control-number-widget-assign').click( function() {
                        var sequence = $( widget.node ).find('.control-number-widget-sequence').val();
                        $.post(
                            '/cgi-bin/koha/svc/cataloguing/control_num_sequences/' + sequence
                        ).done( function( result ) {
                            if ( result.next_value ) widget.setControlNumber( result.next_value );
                        } );
                    } ).end()
                    .find('.control-number-widget-override').click( function() {
                        var result = prompt( _("قم بإدخال رقم تحكم جديد") );

                        if ( result ) widget.setControlNumber( result );
                    } ).end();

                var sequence_list = $.map( reg001 , function( authval ) {
                    return authval.lib;
                } );
                sequence_list.sort();

                $.each( sequence_list, function( undef, sequence ) {
                    $( widget.node ).find('.control-number-widget-sequence').append( '<option>' + sequence + '</option>' );
                } );

                // TODO: Make Enter on select click "Assign"
            }
        } );
        };

    Widget.Register( '005@', {
        init: function() {
            var $result = $( '<span class="subfield-widget fixed-widget">' + _("محدّث: ") + '</span>' );

            return $result[0];
        },
        postCreate: function( node, mark ) {
            var parts = this.text.match( /(\d{4})(\d{2})(\d{2})(\d{2})(\d{2})(\d{2})\.(\d)/ );

            if ( parts ) {
                var dateVal = new Date(
                    parseInt( parts[1] ), // Year
                    parseInt( parts[2] ) - 1, // Month (0-11)
                    parseInt( parts[3] ), // Day
                    parseInt( parts[4] ), // Hour
                    parseInt( parts[5] ), // Minute
                    parseInt( parts[6] ), // Second
                    parseInt( parts[7] ) * 100 // Millisecond
                );

                $( this.node ).append( dateVal.toLocaleString() );
            } else {
                $( this.node ).append( '<span class="hint">' + _("إلغاء ضبط") + '</span>' );
            }
        }
    } );

    Widget.Register( '006@', {
        makeTemplate: function() {
            return "a                 ";
        },
        init: function() {
            var $result = $( '<span class="subfield-widget fixed-widget">' + _("بيانات ثابتة:") + '<span class="hint widget-loading">' + _("جاري التحميل...") + '</span></span>' );

            return $result[0];
        },
        materialTypeMapping: {
            a: 'BKS',
            c: 'MU',
            d: 'MU',
            e: 'MPS',
            f: 'MPS',
            g: 'VM',
            i: 'MU',
            j: 'MU',
            k: 'VM',
            m: 'CF',
            o: 'VM',
            p: 'MX',
            r: 'VM',
            s: 'CR',
            t: 'BKS',
        },
        getMaterial: function () {
            return this.materialTypeMapping[this.text.substring(0, 1)];
        },
        postCreate: function( node, mark ) {
            this.createFromXML( 'marc21/xml/006' );
        }
    } );

    Widget.Register( '007@', {
        makeTemplate: function() {
            return "a       ";
        },
        init: function() {
            var $result = $( '<span class="subfield-widget fixed-widget">' + _("بيانات ثابتة:") + '<span class="hint widget-loading">' + _("جاري التحميل...") + '</span></span>' );

            return $result[0];
        },
        materialTypeMapping: {
            a: 'MPS',
            c: 'ER',
            d: 'GL',
            f: 'TM',
            g: 'PG',
            h: 'MF',
            k: 'NG',
            m: 'MP',
            o: 'KT',
            q: 'NM',
            r: 'RI',
            s: 'SR',
            t: 'TC',
            v: 'VR',
            z: 'UN'
        },
        getMaterial: function () {
            return this.materialTypeMapping[this.text.substring(0, 1)];
        },
        postCreate: function( node, mark ) {
            this.createFromXML( 'marc21/xml/007' ).then(() => {
                $(this.node).find('.material-select').on('change', (e) => {
                    const keys = Object.keys(this.materialTypeMapping);
                    const k = keys.filter(k => this.materialTypeMapping[k] === $(e.target).val());
                    this.setFixed(0, 1, k, '+input');

                    // FIXME There must be a better way to update display
                    const n = $(this.node).find('[name="f00"]');
                    n.triggerHandler('focus');
                    n.triggerHandler('blur');
                });
            });
        }
    } );

    Widget.Register( '008@', {
        makeTemplate: function() {
            var now = new Date();
            return Widget.PadNum( now.getYear() % 100, 2 ) + Widget.PadNum( now.getMonth() + 1, 2 ) + Widget.PadNum( now.getDate(), 2 ) + "b        [% DefaultCountryField008 | html %]||||| |||| 00| 0 [% DefaultLanguageField008 | html %] d";
        },
        init: function() {
            var $result = $( '<span class="subfield-widget fixed-widget">' + _("بيانات ثابتة:") + '<span class="hint widget-loading">' + _("جاري التحميل...") + '</span></span>' );

            return $result[0];
        },
        materialTypeMapping: {
            a: {
                a: 'BKS', c: 'BKS', d: 'BKS', m: 'BKS',
                b: 'CR', i: 'CR', s: 'CR',
            },
            t: 'BKS',
            c: 'MU', d: 'MU', i: 'MU', j: 'MU',
            e: 'MP', f: 'MP',
            g: 'VM', k: 'VM', o: 'VM', r: 'VM',
            m: 'CF',
            p: 'MX',
        },
        getMaterial: function () {
            const record = TextMarc.TextToRecord(this.editor.cm.getValue());

            const leader = record.leader();
            const leader6 = leader.substring(6, 7);
            let materialType = this.materialTypeMapping[leader6];
            if (typeof materialType === 'object') {
                const leader7 = leader.substring(7, 8);
                materialType = materialType[leader7];
            }

            return materialType;
        },
        postCreate: function( node, mark ) {
            this.createFromXML( 'marc21/xml/008' );
        }
    } );
} );

</script>
<!-- / cateditor-widgets-marc21.inc -->
