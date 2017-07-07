import * as blessed from 'blessed';

import { Config } from '../config/config.type';

const auto = true;

export default class Frame {
    config: Config;
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
        })
    }

    init(): void {
        this.screenWillMount()
    }

    screenWillMount(): void {
        let mainBoxOptions: any = {
            parent: this.screen,
            top: 'center',
            left: 'center',
            data: null,
            border: 'line',
            align: 'center',
            tags: true,
            keys: true,
            width: '100%',
            height: '100%',
            content: this.config.title,
            style: {
                fg: '#008b00',
                bold: true,
                border: {
                    bold: true,
                    fg: '#008b00'
                }
            }
        };
        let menuBarOptions: any = {
            parent: this.screen,
            top: 2,
            left: 3,
            bottom: 2,
            data: this.config.items,
            border: 'line',
            align: 'center',
            tags: true,
            keys: true,
            width: 'shrink',
            height: 'shrink',
            vi: true,
            mouse: true,
            style: {
                border: {
                    fg: '#008b00'
                },
                cell: {
                    fg: '#008b00',
                    selected: {
                        bg: '#008b00'
                    }
                }
            }
        };
        let infoBoxOptions: any = {
            parent: this.screen,
            top: 2,
            left: 18,
            right: 3,
            bottom: 2,
            data: null,
            border: 'line',
            align: 'center',
            tags: true,
            keys: true,
            width: 'shrink',
            height: 'shrink',
            content: `...`,
            style: {
                fg: '#008b00',
                bold: true,
                border: {
                    bold: true,
                    fg: '#008b00'
                }
            }
        };

        this.mainBox = blessed.box(mainBoxOptions);
        this.listtable = blessed.listtable(menuBarOptions);
        this.infoBox = blessed.box(infoBoxOptions);

        this.screen.key('q', function () {
            return this.screen.destroy();
        });

        this.listtable.focus();
    }

    render(): void {
        this.screen.render();
    }
}
