import { Config } from '../config/config.type';

export function mainBoxOpt(screen: any, config: Config): any {
    return {
        parent: screen,
        top: 'center',
        left: 'center',
        data: null,
        border: 'line',
        align: 'center',
        tags: true,
        keys: true,
        width: '100%',
        height: '100%',
        content: config.title,
        style: {
            fg: '#008b00',
            bold: true,
            border: {
                bold: true,
                fg: '#008b00'
            }
        }
    };
}

export function menuBarOpt(screen: any, config: Config): any {
    return {
        parent: screen,
        top: 2,
        left: 3,
        bottom: 2,
        data: config.items,
        border: 'line',
        align: 'center',
        tags: true,
        keys: true,
        width: 20,
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
}

export function infoBoxOpt(screen: any, config: Config) {
    return {
        parent: screen,
        top: 2,
        left: 24,
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
        content: `Waiting...`,
        style: {
            fg: '#008b00',
            bold: true,
            border: {
                bold: true,
                fg: '#008b00'
            }
        }
    };
}
