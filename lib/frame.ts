import * as blessed from 'blessed';
import * as fs from 'fs';

import { Config } from '../config/config.type';
import { mainBoxOpt, menuBarOpt, infoTextScrollableOpt } from './components.options';

const auto = true;

export default class Frame {
    config: Config;
    counter: number;
    screen: any;
    mainBox: any;
    listtable: any;
    infoBox: any;

    constructor(config: Config) {
        this.config = config;
        this.screen = blessed.screen({
            smartCSR: true,
            autoPadding: false,
            fullUnicode: true,
            warnings: true
        });
        this.counter = 1;
    }

    init(): void {
        this.screenWillMount()
    }

    screenWillMount(): void {
        let text;
        this.mainBox = blessed.box(mainBoxOpt(this.screen, this.config));
        this.listtable = blessed.listtable(menuBarOpt(this.screen, this.config));
        this.infoBox = blessed.scrollabletext(infoTextScrollableOpt(this.screen, this.config));

        try {
            text = fs.readFileSync(`./info/${this.config.info[this.counter]}`, 'utf-8');
        } catch (error) {
            text = fs.readFileSync(`~/.younglee/${this.config.info[this.counter]}`, 'utf-8');
        }

        this.infoBox.setContent(text);

        this.bindings();

        this.listtable.focus();
    }

    bindings() {
        const _this = this;

        this.listtable.on('keypress', function(ch: any, key: any) {
            let text;
            if (key.name === 'up' || key.name === 'k') {
                if (_this.counter > 1 && _this.counter <= _this.config.info.length - 1) {
                    _this.counter--;
                }
                try {
                    text = fs.readFileSync(`./info/${_this.config.info[_this.counter]}`, 'utf-8');
                } catch (error) {
                    text = fs.readFileSync(`~/.younglee/${_this.config.info[_this.counter]}`, 'utf-8');
                }
                _this.infoBox.setContent(text);
                _this.render();
                return;
            } else if (key.name === 'down' || key.name === 'j') {
                if (_this.counter >= 1 && _this.counter < _this.config.info.length - 1) {
                    _this.counter++;
                }
                try {
                    text = fs.readFileSync(`./info/${_this.config.info[_this.counter]}`, 'utf-8');
                } catch (error) {
                    text = fs.readFileSync(`~/.younglee/${_this.config.info[_this.counter]}`, 'utf-8');
                }
                _this.infoBox.setContent(text);
                _this.render();
                return;
            }
        });

        this.listtable.on('keypress', function(ch: any, key: any) {
            if (key.name === 'right' || key.name === 'l') {
                _this.infoBox.focus();
                return;
            }
        });

        this.infoBox.on('keypress', function(ch: any, key: any) {
            if (key.name === 'left' || key.name === 'h') {
                _this.listtable.focus();
                return;
            }
        });

        this.screen.key('q', function() {
            return this.screen.destroy();
        });
    }

    render(): void {
        this.screen.render();
    }
}
