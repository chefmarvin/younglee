import Frame from '../lib/frame';
import configs from '../config/config';

const lang = 'en';
const frame = new Frame(configs[lang]);

frame.init();
frame.render();
