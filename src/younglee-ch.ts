import Frame from '../lib/frame';
import configs from '../config/config';

const lang = 'ch';
const frame = new Frame(configs[lang]);

frame.init();
frame.render();
