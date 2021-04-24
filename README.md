# Advanced-Parking-Sensor


*Bu projemde Servo Motora bağlı olan bir "HC-SR04" ultrasonik mesafe sensörü ile hem sesli hem de görüntülü uyarı veren bir park uyarı cihazı geliştirdim.

*Servo motorun üst kısmına montajlanan ultrasonik sensörümüz, servo motora gönderilen açı dönüş bilgileriyle yaklaşık 180 derecelik bir alanı tarayacaktır.

*Sensör çevreden aldığı mesafe-engel bilgisini " 16x2'lik " bir LCD ekranda gösterecektir.

*Aynı zamanda belirli bir mesafeden sonra mesafe uyarısını sesli ve görüntülü olarak bir "Buzzer + LED ampül" ile dış ortama iletecektir.

*Yazılım kısmından servo motorun dönüş hızı ve ultrasonik mesafe sensörünün maksimum minimum uzaklığı ayarlanabilir.

*Donanım kısmında LCD displayimizin LED pinine gelen akım çok fazla olduğundan bunu minimuma indirmek için 330 ohm'luk bir direnç bağladım.