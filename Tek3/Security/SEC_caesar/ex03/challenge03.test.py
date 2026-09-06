from challenge03 import cmp_freq
import random


def encrypt_in_xor(sentence, key):
    a = bytearray(sentence)
    for i in range(0, len(sentence)):
        a[i] ^= key
    return bytes(a)


array_test = [
    b'His mind was blown that there was nothing in space except space itself.',
    b'I love bacon, beer, birds, and baboons.',
    b'With a single flip of the coin, his life changed forever.',
    b'If you like tuna and tomato sauce - try combining the two. It\'s really not as bad as it sounds.',
    b'The view from the lighthouse excited even the most seasoned traveler.',
    b'The small white buoys marked the location of hundreds of crab pots.',
    b'Be careful with that butter knife.',
    b'We have young kids who often walk into our room at night for various reasons including clowns in the closet.',
    b'Mary plays the piano.',
    b'The lake is a long way from here.',
    b'Buried deep in the snow, he hoped his batteries were fresh in his avalanche beacon.',
    b'Swim at your own risk was taken as a challenge for the group of Kansas City college students.',
    b'Peanut butter and jelly caused the elderly lady to think about her past.',
    b'They say that dogs are man\'s best friend, but this cat was setting out to sabotage that theory.',
    b'He found a leprechaun in his walnut shell.',
    b'She traveled because it cost the same as therapy and was a lot more enjoyable.',
    b'Had he known what was going to happen, he would have never stepped into the shower.',
    b'She wanted a pet platypus but ended up getting a duck and a ferret instead.',
    b'The near-death experience brought new ideas to light.',
    b'I was very proud of my nickname throughout high school but today - I couldn\'t be any different to what my nickname was.',
    b'It\'s not often you find a soggy banana on the street.',
    b'The doll spun around in circles in hopes of coming alive.',
    b'You\'re unsure whether or not to trust him, but very thankful that you wore a turtle neck.',
    b'Shakespeare was a famous 17th-century diesel mechanic.',
    b'There\'s a message for you if you look up.',
    b'She had the gift of being able to paint songs.',
    b'Hit me with your pet shark!',
    b'Abstraction is often one floor above you.',
    b'David subscribes to the "stuff your tent into the bag" strategy over nicely folding it.',
    b'The rusty nail stood erect, angled at a 45-degree angle, just waiting for the perfect barefoot to come along.',
    b'Joyce enjoyed eating pancakes with ketchup.',
    b'Let me help you with your baggage.',
    b'The door slammed on the watermelon.',
    b'The tour bus was packed with teenage girls heading toward their next adventure.',
    b'The skeleton had skeletons of his own in the closet.',
    b'25 years later, she still regretted that specific moment.',
    b'There were three sphered rocks congregating in a cubed room.',
    b'The thick foliage and intertwined vines made the hike nearly impossible.',
    b'The stranger officiates the meal.',
    b'She says she has the ability to hear the soundtrack of your life.',
    b'I am counting my calories, yet I really want dessert.',
    b'He had unknowingly taken up sleepwalking as a nighttime hobby.',
    b'I\'m confused: when people ask me what\'s up, and I point, they groan.',
    b'He\'s in a boy band which doesn\'t make much sense for a snake.',
    b'Combines are no longer just for farms.',
    b'There are few things better in life than a slice of pie.',
    b'Greetings from the galaxy MACS0647-JD, or what we call home.',
    b'She was the type of girl who wanted to live in a pink house.',
    b'Smoky the Bear secretly started the fires.',
    b'He didn\'t understand why the bird wanted to ride the bicycle.',
    b'He quietly entered the museum as the super bowl started.',
    b'Nobody loves a pig wearing lipstick.',
    b'Shakespeare was a famous 17th-century diesel mechanic.',
    b'He had decided to accept his fate of accepting his fate.',
    b'She saw no irony asking me to change but wanting me to accept her for who she is.',
    b'The lyrics of the song sounded like fingernails on a chalkboard.',
    b'Various sea birds are elegant, but nothing is as elegant as a gliding pelican.',
    b'The newly planted trees were held up by wooden frames in hopes they could survive the next storm.',
    b'She only paints with bold colors; she does not like pastels.',
    b'The urgent care center was flooded with patients after the news of a new deadly virus was made public.',
    b'The light in his life was actually a fire burning all around him.',
    b'I would have gotten the promotion, but my attendance wasn\'t good enough.',
    b'He had a hidden stash underneath the floorboards in the back room of the house.',
    b'There can never be too many cherries on an ice cream sundae.',
    b'The thunderous roar of the jet overhead confirmed her worst fears.',
    b'We should play with legos at camp.',
    b'He was surprised that his immense laziness was inspirational to others.',
    b'Bill ran from the giraffe toward the dolphin.',
    b'The waves were crashing on the shore; it was a lovely sight.',
    b'Check back tomorrow; I will see if the book has arrived.',
    b'The irony of the situation wasn\'t lost on anyone in the room.',
    b'Her hair was windswept as she rode in the black convertible.',
    b'It was the scarcity that fueled his creativity.',
    b'Everyone says they love nature until they realize how dangerous she can be.',
    b'Sometimes, all you need to do is completely make an ass of yourself and laugh it off to realise that life isn\'t so bad after all.',
    b'You\'re unsure whether or not to trust him, but very thankful that you wore a turtle neck.',
    b'She found his complete dullness interesting.',
    b'The paintbrush was angry at the color the artist chose to use.',
    b'his seven-layer cake only had six layers.',
    b'Even though he thought the world was flat he didn\'t see the irony of wanting to travel around the world.',
    b'She tilted her head back and let whip cream stream into her mouth while taking a bath.',
    b'She hadn\'t had her cup of coffee, and that made things all the worse.',
    b'Flying fish few by the space station.',
    b'The blinking lights of the antenna tower came into focus just as I heard a loud snap.',
    b'He poured rocks in the dungeon of his mind.',
    b'Sometimes it is better to just walk away from things and go back to them later when you\'re in a better frame of mind.',
    b'There\'s an art to getting your way, and spitting olive pits across the table isn\'t it.',
    b'I am counting my calories, yet I really want dessert.',
    b'As you consider all the possible ways to improve yourself and the world, you notice John Travolta seems fairly unhappy.',
    b'After exploring the abandoned building, he started to believe in ghosts.',
    b'He invested some skill points in Charisma and Strength.',
    b'The blue parrot drove by the hitchhiking mongoose.',
    b'Had he known what was going to happen, he would have never stepped into the shower.',
    b'It was a slippery slope and he was willing to slide all the way to the deepest depths.',
    b'Going from child, to childish, to childlike is only a matter of time.',
    b'The door slammed on the watermelon.',
    b'They got there early, and they got really good seats.',
    b'There was coal in his stocking and he was thrilled.',
    b'He is good at eating pickles and telling women about his emotional problems.',
    b'The three-year-old girl ran down the beach as the kite flew behind her.',
]

cnt = 0

for sentence in array_test:
    sentence = sentence.lower()
    encryption_key = random.randint(0, 255)

    found_sentence, found_key = cmp_freq(encrypt_in_xor(sentence, encryption_key))
    if (sentence, encryption_key) != (found_sentence, found_key):
        cnt += 1

print(f"number of error found = {cnt}")

# s = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736"
# s2 = bytes.fromhex(s)

# for i in range(0, 256):
#     print(f"res = {encrypt_in_xor(s2, i)}, key = {i}")