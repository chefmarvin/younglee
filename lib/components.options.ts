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
            fg: '#48b317',
            bold: true,
            border: {
                bold: true,
                fg: '#48b317'
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
                fg: '#48b317'
            },
            cell: {
                fg: '#48b317',
                selected: {
                    fg: '#000000',
                    bg: '#48b317'
                }
            }
        }
    };
}

export function infoBoxOpt(screen: any, config: Config): any {
    return {
        parent: screen,
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
            fg: '#48b317',
            bold: true,
            border: {
                bold: true,
                fg: '#48b317'
            }
        }
    };
}

export function infoTextScrollableOpt(screen: any, config: Config): any {
    return {
        parent: screen,
        mouse: true,
        padding: {
            top: 1,
            bottom: 1,
            left: 2,
            right: 2
        },
        top: 2,
        left: 23,
        right: 3,
        bottom: 2,
        width: 'shrink',
        height: 'shrink',
        content: '',
        border: 'line',
        align: 'center',
        tags: true,
        keys: true,
        style: {
            fg: '#48b317',
            bold: true,
            border: {
                bold: true,
                fg: '#48b317'
            }
        },
        scrollbar: {
            track: {
                bg: '#48b317'
            },
            fg: '#ffc125',
            inverse: true
        }
    };
}
