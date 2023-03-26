CLOUDFLARE NOTES

What does Hotlink Protection do?
Hotlink Protection prevents your images from being used by other sites. This can reduce the bandwidth consumed by your origin server.

When Cloudflare receives an image request for your site, we check to ensure the request did not originate from visitors on another site. Visitors to your domain will still be able to download and view images.

Hotlink protection has no impact on crawling, but it will prevent the images from being displayed on sites such as Google images, Pinterest, etc.

Supported file extensions: gif, ico, jpg, jpeg, and png.

Note: Hotlink Protection will deny access to requests when the HTTP referer does not include your website domain name (and is not blank).

Can I allow hotlinking to specific images?
You can allow certain images to be hotlinked by placing them in a directory named hotlink-ok. The hotlink-ok directory can be placed anywhere on your website.

Example: To allow example.com to use logo.png from glennlopez.com, put logo.png in a new folder called hotlink-ok on glennlopez.com. Any images in the hotlink-ok folder will not be checked for hotlinking.

Some examples of URLs that will not be checked for hotlinking:

http://glennlopez.com/hotlink-ok/pic.jpg
http://glennlopez.com/images/hotlink-ok/pic.jpg
http://glennlopez.com/hotlink-ok/images/pic.jpg
http://glennlopez.com/images/main-site/hotlink-ok/pic.jpg