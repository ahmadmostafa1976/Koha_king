<script>
   var showLastPatronCount = "[% Koha.Preference('showLastPatronCount') | html %]";
</script>
<div id="lastborrower-window">
 <div class="btn-group">
 <a class="btn btn-link navbar-btn lastborrower" id="lastborrowerlink" href="#" title=""><i class="fa fa-arrow-right"></i> آخر مستفيد</a>
 <button type="button" data-toggle="dropdown" class="btn btn-link navbar-btn dropdown-toggle" aria-haspopup="true" aria-expanded="false">
 <span class="caret"></span>
 <span class="sr-only">تبديل القائمة المنسدلة</span>
 </button>
 <ul id="lastBorrowerList" class="dropdown-menu dropdown-menu-right">
 <li role="separator" class="divider"></li>
 <li><a id="lastborrower-remove" class="lastborrower" href="#">مسح القائمة</a></li>
 </ul>
 </div>
</div>
