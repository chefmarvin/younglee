import * as blessed from 'blessed';
import * as request from 'request';

import { Config } from '../config/config.type';
import { mainBoxOpt, menuBarOpt, infoBoxOpt } from './components.options';

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
        let _this = this;

        this.mainBox = blessed.box(mainBoxOpt(this.screen, this.config));
        this.listtable = blessed.listtable(menuBarOpt(this.screen, this.config));
        let test: any = {
            parent: this.screen,
            top: 2,
            left: 23,
            right: 3,
            bottom: 2,
            border: 'line',
            align: 'center',
            tags: true,
            keys: true,
            width: 'shrink',
            height: 'shrink',
            padding: {
                left: 2
            },
            content: ``,
            style: {
                fg: '#008b00',
                bold: true,
                border: {
                    bold: true,
                    fg: '#008b00'
                }
            }
        };
        this.infoBox = blessed.box(test);

        this.listtable.on('keypress', function(ch: any, key: any) {
            if (key.name === 'up' || key.name === 'k') {
                if (_this.counter > 1 && _this.counter <= _this.config.info.length - 1) {
                    _this.counter--;
                }
                _this.infoBox.setContent(_this.config.info[_this.counter]);
                _this.render();
                return;
            } else if (key.name === 'down' || key.name === 'j') {
                if (_this.counter >= 1 && _this.counter < _this.config.info.length - 1) {
                    _this.counter++;
                }
                _this.infoBox.setContent(_this.config.info[_this.counter]);
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

        this.listtable.focus();
    }

    render(): void {
        this.infoBox.setContent(this.config.info[this.counter]);
        this.screen.render();
    }
}
