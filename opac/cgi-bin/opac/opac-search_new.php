<?php
header('Content-Type: application/json');

// Database connection or Koha API setup goes here

$search_term = $_GET['q'];

// Query Koha's database or use Koha's internal API
// Assume you have a function `search_catalog` that returns the matching titles
$results = search_catalog($search_term);

$suggestions = [];

foreach ($results as $item) {
    $suggestions[] = [
        'title' => $item['title'],      // Bibliographic title
        'url' => '/cgi-bin/koha/opac-detail.pl?biblionumber=' . $item['biblionumber']  // Detail page URL
    ];
}

// Return the suggestions as JSON
echo json_encode($suggestions);
